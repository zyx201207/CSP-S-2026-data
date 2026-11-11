#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
}x[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i].a>>x[i].c;
	int cnt1=x[1].a,cnt2=x[n].a;
	long long ans=0;
	for(int i=1,j=n;i<j;){
		if(cnt2<cnt1){
			ans+=1ll*(x[i].c!=x[j].c)*cnt2;
			cnt1-=cnt2;
			j--;
			cnt2=x[j].a;
		}
		else if(cnt2>cnt1){
			ans+=1ll*(x[i].c!=x[j].c)*cnt1;
			cnt2-=cnt1;
			i++;
			cnt1=x[i].a;
		}
		else{
			ans+=1ll*(x[i].c!=x[j].c)*cnt1;
			j--;
			i++;
			cnt1=x[i].a;
			cnt2=x[j].a;
		}
	}
	cout<<ans;
	return 0;
}
