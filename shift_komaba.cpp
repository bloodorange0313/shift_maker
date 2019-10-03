#include<iostream>
#include<deque>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;

string name[105];
string wanted[105];
string unwanted[105];
int n, m;
int shift_number[105];
pair<string, int> person[105];
unordered_map<string, string>M1, M2; // あとで、wanted, unwantedを決めるために使う
unordered_map<string, int>cnt_kaisu;
int able[105][105];
queue<string>okunai[105], okugai[105], yatai[105];

priority_queue<pair<int, string> > Q[105];

// シフトの入れるところを全てpriority queueに入れる
void solve_one(){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(able[j][i] > 0){
        Q[j].push(make_pair(cnt_kaisu[name[i]], name[i]));
        cnt_kaisu[name[i]]++;
      }
    }
  }
}


// 今度は、シフトが余っている場合に、ポイントが大きい人から出す。
void solve_two(){
  for(int i = 0; i < m; ++i){
    while(Q[i].size() > shift_number[i]){
      pair<int, string> nukedashi;
      nukedashi = Q[i].top();
      Q[i].pop();
      //cout << nukedashi.second << endl;
    }
  }
}

// 屋内・屋外・屋台を割り当てる。しかし、複雑なので、希望を可視化するに止める
void solve_three(){
  for(int i = 0; i < m; ++i){
    
    while(!Q[i].empty()){
      pair<int, string> s;
      s = Q[i].top();
      Q[i].pop();
      //cout << s.second << endl;
      if(M1[s.second] == "屋台"){
        yatai[i].push(s.second);
        //cout << s.second << endl;
      }else if(M1[s.second] == "屋内"){
        okunai[i].push(s.second);
      }else{
        okugai[i].push(s.second);
      }
    }
  }
}

void solve_four(){
  for(int i = 0; i < m; ++i){
    cout << i << "番目のシフトに入ってもいい人" << endl;
    while(!yatai[i].empty()){
      cout << "屋台希望" << endl;
      string s;
      s = yatai[i].front();
      yatai[i].pop();
      cout << s << endl;
    }
    while(!okunai[i].empty()){
      cout << "屋内希望" << endl;
      string s;
      s = okunai[i].front();
      okunai[i].pop();
      cout << s << endl;
    }
    while(!okugai[i].empty()){
      cout << "屋外希望" << endl;
      string s;
      s = okugai[i].front();
      okugai[i].pop();
      cout << s << endl;
    }
  }
}

int main(){
  // 人数とシフトの時間帯の枠の個数をインポート
  cin >> n >> m;
  // シフトの時間に関する情報の入力
  for(int i = 0; i < m; ++i){
    cin >> shift_number[i];
  }
  // 各個人のシフトに関する希望を入力
  for(int i = 0; i < n; ++i){
    cin >> name[i] >> wanted[i] >> unwanted[i];
    //cout << wanted[i] << endl;
    M1[name[i]] = wanted[i];
    M2[name[i]] = unwanted[i];
    for(int j = 0; j < m; ++j){
      cin >> able[j][i];
      //cout << able[j][i] << endl;
    }
  }
  //cout << m << endl;
  solve_one();
  solve_two();
  solve_three();
  solve_four();

  /*
  for(int i = 0; i < m; ++i){
    cout << i << "番目のシフトに入ってもいい人" << endl;
    while(!Q[i].empty()){
      pair<int, string> s;
      s = Q[i].top();
      Q[i].pop();
      cout << s.second << endl;
    }

  }
  */
  
 /*
 //point数を確認するプログラム
 for(int i = 0; i < n; ++i){
   cout << cnt_kaisu[name[i]] << endl;
 }
 */

  
  
}