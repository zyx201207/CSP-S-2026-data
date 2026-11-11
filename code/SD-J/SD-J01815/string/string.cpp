#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200100;
struct node{
	int c;
	char cc;
}a[N];
ll ss,s,mid,ans;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].cc;
		s+=a[i].c;
	}
	if(s%2==1){
		mid=(s+1)/2;
		for(int i=1;i<=n;i++){
			ss+=a[i].c;
			if(ss==mid-1){
				a[i+1].c--;
				break;
			}
			if(ss==mid){
				a[i].c--;
				break;
			}
			if(ss>mid){
				n++;
				for(int j=n;j>=i+2;j--){
					a[j].c=a[j-1].c;
					a[j].cc=a[j-1].cc;
				}
				a[i].c=mid-ss+a[i].c-1;
				a[i+1].c=ss-mid;
				a[i+1].cc=a[i].cc;
				break;
			}
		}
	}
	else{
		mid=s/2;
		for(int i=1;i<=n;i++){
			ss+=a[i].c;
			if(ss==mid)break;
			if(ss>mid){
				n++;
				for(int j=n;j>=i+2;j--){
					a[j].c=a[j-1].c;
					a[j].cc=a[j-1].cc;
				}
				a[i].c=mid-ss+a[i].c;
				a[i+1].c=ss-mid;
				a[i+1].cc=a[i].cc;
				break;
			}
		}
	}
	int l=n/2,r=n/2;
	ll sl=0,sr=0;
	for(int l=n/2;l>=1;l--){
		while(sr<sl){
			if(a[r].cc!=a[l].cc)ans+=a[r].c;
			r++;
			sr+=a[r].c;
		}
		if(sr>sl){
			if(a[r].cc!=a[l].cc)ans+=sl-(sr-a[r].c);
		}
	}
	cout<<ans; 
	return 0;
}
