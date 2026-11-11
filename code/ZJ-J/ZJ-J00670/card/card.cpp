#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010]={},b[500010]={},len=0;
int ans[300010]={};
stack<int> s;
void check(int a){
	while(s.size()!=0)s.pop();
	for(int i=len;i>=1;i--){
		if(b[i]==a){
			s.push(b[i]);
			b[i]==0;
			len=i-1;
			return ;
		}
		else{
			s.push(b[i]);
			b[i]==0;
		}
	}
	for(int i=1;i<=len;i++){
		b[i]=s.top();
		s.pop();
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=INT_MIN;
	for(int i=1;i<=n;i++){
		int c[500010]={},lenc=n;
		for(int i=1;i<=500010;i++){
			c[i]=a[i];
			b[i]=0;
		}
		len=0;
		for(int j=i;j<=n;j++){
			check(c[j]);
			b[++len]=c[j];
		}
		for(int j=1;j<=len;j++){
			a[b[j]]++;
		}
		maxn=max(maxn,len);
	}
	for(int i=1;i<=maxn;i++){
		cout<<a[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}