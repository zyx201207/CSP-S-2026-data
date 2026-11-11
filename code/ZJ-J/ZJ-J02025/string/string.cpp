#include<bits/stdc++.h>
using namespace std;
#define int long long

pair<int,string> a[200005];
int pre[200005];
string s;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,to=0,ans=0,mx=0;
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		pre[i]=pre[i-1]+a[i].first;
		to+=a[i].first;
		mx=max(a[i].first,mx);
	}
	//cout<<mx<<endl;
	if(mx<=500){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].first;j++){
				s+=a[i].second;
			}
		}
		//cout<<s.length()<<" "<<s<<endl;
		for(int i=0;i<s.length()/2;i++){
			if(s[i]!=s[s.length()-i-1])ans++;
			//cout<<"ans:"<<ans<<endl;
		}
		cout<<ans<<endl;
	}else{
//		int l=0,r=pre[n]+1,jd_l=1,jd_r=n,flag;
//		char now_l=a[1].second,now_r=a[n].second;
//		if(n%2){
//			flag=1;
//		}else{
//			flag=0;
//		}
//		while(l<=pre[n]/2 && r>=pre[n]/2+1+flag){
//			int next_l=min(pre[jd_l+1]-1,pre[n]/2);
//			int next_r=max(pre[n]-pre[jd_r-1]+1,pre[n]/2+1+flag);
//			if(next_l-l<r-next_r){
//				l+=next_l-l;r-=next_l-l;
//				if(a[jd_l].second!=a[jd_r].second){
//					ans+=next_l-l;
//				}
//				jd_l++;
//			}else if(next_l-l>r-next_r){
//				l+=r-next_r;r-=r-next_r;
//				if(a[jd_l].second!=a[jd_r].second){
//					ans+=r-next_r;
//				}
//				jd_r--;
//			}else{
//				l+=r-next_r;r-=r-next_r;
//				if(a[jd_l].second!=a[jd_r].second){
//					ans+=r-next_r;
//				}
//				jd_r--;
//				jd_l++;
//			}
//		}
//		if(l<=pre[n]/2){
//			if(a[jd_l-1].second!=a[jd_r].second){
//				ans+=r-(pre[n]/2+1+flag);
//			}
//		}
//		if(r>=pre[n]/2+1+flag){
//			if(a[jd_l].second!=a[jd_r+1].second){
//				ans+=pre[n]/2-l;
//			}
//		}
//		cout<<ans<<endl;
	}
	return 0;
}
