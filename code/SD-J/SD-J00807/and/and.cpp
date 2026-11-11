#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
bool f[200005][35];
struct node{
	int prev,nxt;
}l[200005];
int h=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[h].prev=i;
		l[i]={0,h};
		h=i;
		int pos=0,aaa=a[i];
		while(aaa!=0){
			pos++;
			if(aaa%2==1){
				f[i][pos]=1;
			}
			aaa/=2;
		}
	}
	for(int i=32;i>=1;i--){
		int cnt=0;
		for(int j=h;j!=0;j=l[j].nxt){
			if(f[j][i]==1){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=h;j!=0;j=l[j].nxt){
				if(f[j][i]==0){
					if(j==h){
						h=l[j].nxt;
						l[l[j].nxt].prev=0;
					}
					else{
						l[l[j].prev].nxt=l[j].nxt;
						l[l[j].nxt].prev=l[j].prev;
					}
				}
			}
		}
	}
	int ans=a[h];
	for(int i=h;i!=0;i=l[i].nxt){
		ans&=a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
