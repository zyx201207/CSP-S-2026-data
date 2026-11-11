#include<bits/stdc++.h>
using namespace std;
//priority_queue<int>a;
//vector<int>s;
const int N=2e5+5;
int n;
char s[N];
long long ans,mid,a[N],all,ll,l,r,l1,r1,l2,r2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		all+=a[i];
	}
	ll=all/2;
	for(int i=1;i<=n;i++){
		if(ll>a[i])ll-=a[i];
		else{mid=i;l=ll,r=a[i]-ll;break;}
	}
	l1=1;
	r1=n;
	l2=a[1];
	r2=a[n];
	while(l1<=mid&&r1>=mid){
		if(s[l1]!=s[r1]){
			ans+=min(l2,r2);
		}
			if(r2>l2){
				r2-=l2;
				l1++;
				l2=a[l1];
				if(l1==mid){
					l2=l;
				}
			}else if(r2<l2){
				l2-=r2;;
				r1--;
				r2=a[r1];
				if(r1==mid){
					r2=r;
				}
			}else{
				l1++;
				l2=a[l1];
				if(l1==mid){
					l2=l;
				}
				r1--;
				r2=a[r1];
				if(r1==mid){
					r2=r;
				}
			}
	}
	cout<<ans;
	return 0;
}
