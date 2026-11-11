#include<bits/stdc++.h>
using namespace std;
const int  N = 3e5+5;
int n,m,b[N],t[N],a[N],flag[N]; 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int len = 0,cnt = 0;
		for(int j=i;j<=n;j++){
			//cout<<b[j]<<" ";
			if(len==0)	cnt=-1;
			else cnt = lower_bound(a+1,a+1+len,b[j])-a;
			if(a[cnt]==b[j]&&cnt<=len){
				len = cnt-1;
			}
			if(cnt == -1){
				len = 0;
			}
			a[++len] = b[j];
		}
		//cout<<"\n--------------\n";
		for(int j=1;j<=len;j++){
			flag[a[j]] = 1;
			//cout<<a[j]<<" ";
		}
		//cout<<"\n++++++++++++\n";
		for(int j=1;j<=m;j++){
			t[j] += flag[j];
			flag[j] = 0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
