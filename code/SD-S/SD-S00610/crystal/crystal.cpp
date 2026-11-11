#include<bits/stdc++.h> 
using namespace std;
const int N=5E5+5;
long long num[N];
priority_queue<int> q[N];
long long ans[N];
long long sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>num[i];
		sum[i]=m;
	}
	sort(num+1,num+n+1);
	if (n<=5000){
		for (int i=1;i<=n;i++){
			int j=i+1;
			while (j<=n&&num[i]+m>=num[j]){
				if (sum[j]<(num[j]-num[i])){
					if ((num[j]-num[i])<q[j].top()){
						sum[j]=sum[j]+q[j].top()-(num[j]-num[i]);
						q[j].pop();
						q[j].push(num[j]-num[i]);
					}
				}
				else{
					q[j].push(num[j]-num[i]);
					sum[j]-=(num[j]-num[i]);
				}
				j++;
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			int now_ans=q[i].size();
			ans=max(ans,now_ans);
		}
		cout<<ans+1;
	}
	else{
		long long jg=num[2]-num[1];
		long long m_ans=0;
		num[1]=1;
		for (int i=2;i<=n;i++){
			num[i]=num[i-1]+jg;
		}
		for (int i=2;i<=n;i++){
			long long tot_m=(num[i-1]+num[1])*i/2;
			if (tot_m<=m){
				ans[i]=i;
			}
			else{
				int l=1,r=i-1;
				while (l<r){
					int mid=(l+r)>>1;
					long long tot_mid=(num[i-1]+num[i-mid])*mid/2;
					if (tot_mid<m) l=mid+1;
					else r=mid;
				}
				ans[i]=l+1;
			}
			m_ans=max(m_ans,ans[i]);
		}
		cout<<m_ans;
	}
	return 0;
}
