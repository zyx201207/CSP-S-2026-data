#include<bits/stdc++.h>
using namespace std;
int n,newn,m,t[500005],a[500005],ans[300005],cnt,pos=1;
bool A=1; 
stack<int>s;
bool has[300005];
int main(){
	freopen("card.in","r",stdin),freopen("card.out","w",stdout),ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>t[i],A=A&&(t[i-1]<=t[i]);
	if(A){
		for(int i=1;i<=m;i++){
			ans[i]=ans[i-1];
			while(t[pos]<=i&&pos<=n)
				pos++,ans[i]++;
			cout<<ans[i]<<" ";
		}return 0;
	}for(int i=1;i<=n;i++){
		cnt=0,newn=0,memset(has,0,sizeof(has));
		for(int j=i;j<=n;j++){
			if(t[j-1]!=t[j]&&j>i){
				a[++newn]=t[j-1];
				if(cnt>=2)
					a[++newn]=t[j-1];
				cnt=0;
			}cnt++;
		}a[++newn]=t[n];
		if(cnt>=2)
			a[++newn]=t[n];
		for(int j=1;j<=newn;j++){
			if(!has[a[j]])
				s.push(a[j]),has[a[j]]=1;
			else
				while(s.top()!=a[j])
					has[s.top()]=0,s.pop();
		}while(!s.empty())
			ans[s.top()]++,s.pop();
	}for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
