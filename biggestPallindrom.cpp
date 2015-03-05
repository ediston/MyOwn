  // given a string, find the biggest pallindrom  and print it;
  #include<iostream>
  #include<vector>
  #include<string>
  using namespace std;
  // max length is N
  #define N 3002
  int rem[N][N] = {0};
  string s;

  int main(){
    //cin >> s;
    s= "eeegeeksforskeeggeeks";
    int n = s.length();
    int k;
    int ml = 0;
    for(int len=1; len<=n; len++){
      for(int i=0;  i<n; i++){
        if(s[i] == s[i+len-1]){
          if(len == 1)
            rem[i][len] = 1;
          else
            rem[i][len] = 2+rem[i+1][len-2];
        }else{
          rem[i][len] = max(rem[i+1][len-1], rem[i][len-1]);
        }
        ml = max(ml, rem[i][len]);
      }
    }
    cout << rem[0][n]<< endl;
    string left = "", right = "";
    int i= 0, len = n;
    while(i<n && len>=1){
        if(len == 1){
            left = left + s[i];
            break;
        }else if(s[i] == s[i+len-1]){
            left = left + s[i];
            right = s[i] + right;
            i++; len-=2;
        }else{
            if(rem[i+1][len-1] > rem[i][len-1]){
                i++;
            }
            len--;
        }
    }
    cout << left << right << endl;
    return 0;
  }
