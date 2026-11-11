#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct node{
    ll n;
    char c;
};
vector<node> a;
int li, ri;
int m;
ll ans;
node l, r;
int main(){
	 freopen("string.in","r",stdin);
     freopen("string.out","w",stdout)	;
     cin >> m;
     for(int i = 1; i <= m;  i++){
          node x;
          cin >> x.n >> x.c;
          a.push_back(x);
        //  cout << a[i-1].n << ' ' << a[i-1].c << endl;
     }
     li = 0;
     ri = m-1;
     l.n = a[0].n;
     l.c = a[0].c;
     r.n = a[m-1].n;
     r.c = a[m-1].c;
     while(ri > li){
		 
          if(l.n>r.n){
			  //cout << "ok " << li << " " << ri << endl;
              if(l.c!=r.c){
                   ans+=r.n;
              } 
              l.n-=r.n;
              ri--;
              r = a[ri];
              continue;
          }
          if(l.n<r.n){
			  //cout << "ook " << li << " " << ri << endl;
              if(l.c!=r.c){
                  ans+=l.n;
              }          
              r.n-=l.n;
              li++;
              l=a[li];
              continue;
          }
          if(l.n==r.n){
			  //cout << "oook" << endl;
              if(l.c!=r.c){
                  ans+=l.n;
              }
              li++;
              ri--;
              l=a[li];
              r=a[ri];
              continue;
          }
          
     }
     cout << ans << endl;
     return 0;
     
}
