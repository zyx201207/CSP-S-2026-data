#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Node{
	ll num;
	char ch;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	ll sum=0;
	string s1="",s2="";
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
		sum+=a[i].num;
		for(int j=1;j<=a[i].num;j++)s1+=a[i].ch;
		for(int j=1;j<=a[i].num;j++)s2=a[i].ch+s2;
	}
	ll ans=0;
	for(int i=0;i<int(s1.size())/2;i++){
		if(s1[i]!=s2[i])ans++;
	}
	cout<<ans;
//	ll hal=sum/2,len1=0,len2=0;
//	for(int i=1,ll su=0;i<=n;i++){
//		su+=a[i];
//		if(su>=hal){
//			len1=i;
//			break;
//		}
//	}
//	for(int i=n,ll su=0;i>=1;i--){
//		su+=a[i];
//		if(su>=hal){
//			len2=i;
//			break;
//		}
//	}
//	ll lsum=a[1].num,rsum=a[n].num,ans=0;
//	for(int l=1,r=n;;l++){
//		if(lsum<rsum){
//			while(l<len1 && lsum<rsum){
//				l++,lsum+=rsum;
//				if(lsum<=rsum){
//					if(a[l].ch!=a[r].ch){
//						ans+=a[l].num;
//					}
//				}else{
//					if(a[l].ch!=a[r].ch)
//					ans+=a[l].sum-(rsum-lsum);
//				}
//			}
//		}else if(lsum>rsum){
//			while(r>n-len2 && lsum<rsum){
//				l++,lsum+=rsum;
//				if(lsum<=rsum){
//					if(a[l].ch!=a[r].ch){
//						ans+=a[l].num;
//					}
//				}else{
//					if(a[l].ch!=a[r].ch)
//					ans+=a[l].sum-(rsum-lsum);
//				}
//			}
//		}
//	}
	return 0;
}
//Trick||Treat!
