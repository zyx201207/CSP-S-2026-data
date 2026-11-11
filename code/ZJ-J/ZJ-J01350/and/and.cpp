#include<bits/stdc++.h>
using namespace std;
int n,m,num[35],b[200010],a[200010][35];
bool c[200010][5];
void make_two(int i){
	int j=0;
	while(b[i]){
		a[i][j]=b[i]&1;
		b[i]>>=1;
		num[j]+=a[i][j];
		j++;
	}
	return;
}
bool check(int i){
	int aaa=0;
	for(int j=1;j<=n;j++){
		if(!a[j][i]){
			c[j][2]=false;
		}
		if(c[j][2]){
			aaa++;
		}
	}
	if(aaa<m){
		for(int j=1;j<=n;j++){
			c[j][2]=c[j][1];
		}
		return false;
	}
	else{
		for(int j=1;j<=n;j++){
			c[j][1]=c[j][2];
		}
		return true;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int ans=0;
	for(int i=1;i<=200005;i++){
		c[i][1]=true;
		c[i][2]=true;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		make_two(i);
	}
	for(int i=32;i>=0;i--){
		if(num[i]>=m){
			if(check(i)){
				ans+=1<<i;
			}
		}
	}
	cout<<ans;
}