#include<bits/stdc++.h>
using namespace std;
vector<int> c;
int abc(int t,int len){
	for(int i=0;i<len-1;i++) if(c[i]==t) return i;
	return len+1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int b[n+1],a[n+1],kind[m+1]={0},len=0,kind1[m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			len++;
			c.push_back(a[j]);
			kind[a[j]]++;
			for(int k=len;k>=abc(a[j],len);k--){
				kind[c[len]]--;
				c.pop_back();
				len--;
			}
		}
		for(int j=1;j<=m;j++) if(kind[j]!=0) kind1[j]++;
		for(int j=1;j<=n;j++) a[j]=b[j];
		for(int j=1;j<=m;j++) kind[j]=0;
		len=0;
	}
	for(int i=1;i<=m;i++) cout<<kind1[i]<<' ';
	return 0;
}