#include<bits/stdc++.h>
using namespace std;
int n,m,a[300001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		cout<<n;
	}else if(m==2){
		int la[5];
		for(int i=1;i<=n;i++){
			cin>>a[i];
			la[a[i]]=i;
		}
		cout<<la[1]<<' '<<la[2];
	}else{
		int t[m+10],s[m+10];
		for(int i=1;i<=n;i++){
			cin>>a[i];
			t[a[i]]++;
		}
		s[0]=0;
		for(int i=1;i<=m;i++)
			s[i]=s[i-1]+t[i];
		for(int i=1;i<=m;i++)
			cout<<s[i]<<' ';
	}
	return 0;
}
