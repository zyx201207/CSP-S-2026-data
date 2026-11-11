#include<iostream>
#include<stack>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans[N],flag[N],cnt,sum;
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>500){
		for(int i=1;i<=n;i++){
			if(i==1)cnt++;
			else if(a[i]==a[i-1])cnt++;
			else{
				sum+=cnt;
				ans[a[i-1]]=sum;
				cnt=1;
			}
		}
		ans[a[n]]=sum+cnt;
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!flag[a[j]]){
				q.push(a[j]);
				flag[a[j]]=1;
			}
			else{
				while(q.top()!=a[j]){
					flag[q.top()]=0;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			flag[q.top()]=0;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
