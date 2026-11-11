#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],cnt[300005],pos[300005],out;
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		//cout<<i<<endl;
		memset(cnt,0,sizeof(cnt));
		memset(pos,0,sizeof(pos));
		out=0;
		for(int j=i;j<=n;j++){
		//	cout<<j<<' '<<cnt[a[j]]<<' '<<pos[a[j]]<<endl;
			if(cnt[a[j]]==1){
				while(s.top()!=pos[a[j]]){
					//cout<<s.top()<<' '<<cnt[s.top()]<<' '<<pos[s.top()-out]<<endl;
					cnt[s.top()]=0;
					pos[s.top()]=0;
					out++;
					s.pop();
				}
			}
			else{
				pos[a[j]]=j-out;
				cnt[a[j]]++;
				s.push(a[j]);
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
