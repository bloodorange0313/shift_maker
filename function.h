#include<iostream>
#include<deque>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;

string name[225];
string wanted[225];
string unwanted[225];
int n, m;
int shift_number[225];
pair<string, int> person[225];
unordered_map<string, string>M1, M2; // あとで、wanted, unwantedを決めるために使う
unordered_map<string, int>cnt_kaisu;
int able[225][225];
queue<string>okunai[225], okugai[225], yatai[225];
string a, b, c, a1, a2, a3, t[225];

priority_queue<pair<int, string> > Q[225];


vector<pair<int, string> >V[225];

// シフトの入れるところを全てpriority queueに入れる
void solve_one(){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(able[j][i] > 0){
        cnt_kaisu[name[i]]++;
        Q[j].push(make_pair(cnt_kaisu[name[i]], name[i]));
      }
    }
  }
}


// 今度は、シフトが余っている場合に、ポイントが大きい人から出す。
void solve_two_new(){
  for(int i = 0; i < m; ++i){
      while(!Q[i].empty()){
        pair<int, string> nukedashi;
        nukedashi = Q[i].top();
        V[i].push_back(make_pair(cnt_kaisu[nukedashi.second], nukedashi.second));
        Q[i].pop();
      }
      sort(V[i].begin(), V[i].end());
      //cout << i << "ばんめ" << endl;
      //for(int j = 0; j < V[i].size(); ++j){
        //cout << V[i][j].second << " " <<cnt_kaisu[V[i][j].second] << endl;
      //}
      //cout << V[i].size() << " " << shift_number[i] << endl;
      if(V[i].size() > shift_number[i]){
        for(int j = V[i].size() - 1; j >= shift_number[i]; --j){
          //cout << V[i][j].second << endl;
          cnt_kaisu[V[i][j].second]--;
          V[i].erase(V[i].begin() + j);
        }
      }
  }

}

// 屋内・屋外・屋台を割り当てる。しかし、複雑なので、希望を可視化するに止める
void solve_three_new(){
  for(int i = 0; i < m; ++i){
    for(int j = 0; j < V[i].size(); ++j){
      if(M1[V[i][j].second] == "屋台"){
        yatai[i].push(V[i][j].second);
      }else if(M1[V[i][j].second] == "屋内"){
        okunai[i].push(V[i][j].second);
      }else{
        okugai[i].push(V[i][j].second);
      }
    }
  }
}

void solve_four(){
  for(int i = 0; i < m; ++i){
    //cout << i << "番目のシフトに入ってもいい人" << endl;
    cout << t[i] << endl;
    cout << "屋台" << endl;
    while(!yatai[i].empty()){
      string s;
      s = yatai[i].front();
      yatai[i].pop();
      cout << s << endl;//" 希望しないのは"<< M2[s] << endl;
    }
    cout << endl;
    cout << "屋内" << endl;
    while(!okunai[i].empty()){
      
      string s;
      s = okunai[i].front();
      okunai[i].pop();
      cout << s << endl;//" 希望しないのは"<< M2[s] <<  endl;
    }
    cout << endl;
    cout << "どちらでも良い" << endl;
    //cout << "屋外" << endl;
    while(!okugai[i].empty()){
      
      string s;
      s = okugai[i].front();
      okugai[i].pop();
      cout << s << endl; //" 希望しないのは"<< M2[s] << endl;
    }
    cout << endl;
    cout << endl;
  }
}

// シフト割り当ての全体の結果を出力
void solve_five_new(){
  for(int i = 0; i < m; ++i){
    //cout << i << "番目のシフト" << endl;
    cout << t[i] << endl;
    for(int j = 0; j < V[i].size(); ++j){
      cout << V[i][j].second << endl;
    }
    cout << endl;
  }
}