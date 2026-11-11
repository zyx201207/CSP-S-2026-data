#include<bits/stdc++.h>
using namespace std;
long long int c,t,n,d,m[2000005],a[2000005],l,ans,p,ans1,ans2,j; 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int q=1;q<=t;q++){
		cin>>n>>d;
		l=1;
		for(int i=1;i<=n;i++){
			cin>>m[i];
			for(;l<=i;l++){
				if((m[i]-m[l])<=d){
					break;
				}
			}
			a[i]=i-l;
			a[1]=1;
			if(a[i]==a[i-1]&&a[i]==2){
				p=1;
				ans++;
			}
			if(p==1){
				if(a[i]==a[i-1]+1||a[i]==1){
					ans++;
				}else{
					p=0;
				}
			}
		}
		cout<<ans<<endl;
		ans=0; 
		p=0;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 3
0 3 6 7 8 9 10 11 14 17

0 1
10 3
0 3 6 7 8 9 10 13 16 19
*/