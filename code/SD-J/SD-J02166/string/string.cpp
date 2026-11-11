#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n,a[200005],cha=0,ans=0;
char c[200005],ch,bl;
signed main(){
	fast;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(cha!=0){
			if(bl=='r'){
				if(cha==a[l]){
					if(ch!=c[l])ans+=cha;
					cha=0;
					l++;r--;
				}
				else if(cha>a[l]){
					if(ch!=c[l])ans+=a[l];
					cha-=a[l];
					l++;
				}
				else if(cha<a[l]){
					if(ch!=c[l])ans+=cha;
					cha=a[l]-cha;ch=c[l];bl='l';
					r--;
				}
			}
			else if(bl=='l'){
				if(cha==a[r]){
					if(ch!=c[r])ans+=cha;
					cha=0;
					l++;r--;
				}
				else if(cha>a[r]){
					if(ch!=c[r])ans+=a[r];
					cha-=a[r];
					r--;
				}
				else if(cha<a[r]){
					if(ch!=c[r])ans+=cha;
					cha=a[r]-cha;ch=c[r];bl='r';
					l++;
				}
			}
		}
//-----------------------I_LOVE_CCF------------------------------------------------
		else {
			if(a[l]==a[r]){
				if(c[l]!=c[r]){
					ans+=a[l];
				}
				l++;r--;
			}
			else if(a[l]<a[r]){
				cha=a[r]-a[l];ch=c[r];bl='r';
				if(c[l]!=c[r]){
					ans+=a[l];
				}
				l++;
			}
			else if(a[l]>a[r]){
				cha=a[l]-a[r];ch=c[l];bl='l';
				if(c[l]!=c[r]){
					ans+=a[r];
				}
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}


