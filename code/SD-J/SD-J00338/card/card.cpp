#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500002],v[300002],q[300002],t,s[300002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		for(int j=n;j>=1;j--){
			if(v[a[j]]==0){
				v[a[j]]=1;
				q[++t]=a[j];
			}
			else{
				for(;t!=0;){
					if(q[t]==a[j]){
						break;
					}
					v[q[t]]=0;
					t--;
				}
			}
			for(int i=1;i<=t;i++){
				s[q[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<s[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)v[j]=0;
		t=0;
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0){
				v[a[j]]=1;
				q[++t]=a[j];
			}
			else{
				for(;t!=0;){
					if(q[t]==a[j]){
						break;
					}
					v[q[t]]=0;
					t--;
				}
			}
		}
		for(int j=1;j<=t;j++){
			s[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
