#include<bits/stdc++.h>
using namespace std;

const int N  = 1e5 + 100;
int n, m;
int cz[10001];
vector<int> a;
int czx[10001];
vector<int> on;
int ans[10001];
int main(){
     cin >> n >> m;
     for(int i = 1; i <= n; i++){
          int x;
          cin >> x;
          a.push_back(x);
     }
     for(int i = 0; i <= n-1; i++){
          for(int j = i; j<= n-1;  j++){
              if(cz[a[j]]!=0) {
                   for(int l = czx[a[j]]; l <= j-1; l++){
                         a.push_back(on[l]);
                         cz[on[l]]--;
                         on[l]=0;       
                                    
                   }             
              }
              cz[a[j]]=1;
              czx[a[j]]=j;
              on.push_back(a[j]);
          }
          for(int i = 0; i <= m-1; i++){
               if(cz[i]!=0)ans[i]++;
          }
     }
     for(int i = 0; i<= m-1; i++){
          cout << ans[i] << ' ';
     }
     return 0;
}
