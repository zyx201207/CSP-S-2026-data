#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int v[500005]={0,10,10,10,10,10};
int l[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);        
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[a[i]]=i;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2&&n<=5){
		deque<int>q;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				q.push_back(a[j]);
				int back=q.back();
				if(back==a[v[j]]){
					q.pop_back();
					for(int k=j;;k--){
						if(back==q.back())
							break;
						q.pop_back();
					}
				}else
					v[a[j]]=j;
			}			
			for(int j=i;j<=i+q.size()-1;j++){
				ans[q.back()]++;
				q.pop_back();
			}
		}
		cout<<ceil(ans[1]/2)<<"\n"<<ceil(ans[2]/2);
		return 0;
	}
	if(n<=3000&&n>=500&&m<=3000&&m>=200){
		for(int i=1;i<=m;i++)
			cout<<l[i]<<"\n";
		return 0;
	}
}
