#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005],tp[300005];
int read(){
	char ch;
	int sum=0;
	ch=getchar();
	while(1){
		sum=sum*10+(ch-'0');
		ch=getchar();
		if(ch<'0'||ch>'9')break;
	}
	return sum;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		tp[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			j=tp[a[j]];
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
