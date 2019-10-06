#include "function.h"


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
  solve_two_new();
  solve_three_new();
  solve_four();

  //cout << " " << endl;
  //solve_five();
  
  return 0;
}