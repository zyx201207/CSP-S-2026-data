#include<bits/stdc++.h>
using namespace std;
long long n,x[300005],m;
long long a[300005],top;
int t[300005],t2[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			t[x[j]]++;
			if(t[x[j]]>1){
				while(a[top]!=x[j]){
					t[a[top]]--;
					top--;
				}
				t[x[j]]=1;
			}else{
				a[++top]=x[j];
			}
		}
		while(top>=0){
			t2[a[top]]++;
			top--;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<t2[j]<<' ';
	}	
	return 0;
}
