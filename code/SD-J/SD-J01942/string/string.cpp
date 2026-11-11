#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[200005];
char s1[200005];
struct kk{
	char s;
	ll cnt;
}l[200005],r[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ll n;
	cin>>n;
	ll cnt=0;
	for (ll i=1;i<=n;i++){
		cin>>s[i]>>s1[i]; 
		cnt+=s[i];
	}
	ll sum=0;
	ll mid;  
	for (ll i=1;i<=n;i++){
		sum+=s[i];
		if (sum>cnt/2){
			if (cnt/2-(sum-s[i])!=0){
				l[i].s=s1[i],l[i].cnt=cnt/2-(sum-s[i]);
				s[i]-=cnt/2-(sum-s[i]);
				mid=i;
			}else{
				mid=i-1;
			}
			break;
		}else{
			l[i].s=s1[i],l[i].cnt=s[i];
		}
	}
	ll n1=mid;
	mid++;
	if (cnt%2==1){
		s[mid+1]-=1;
	}
	//cout<<"\n\n\n";
	//for (ll i=1;i<=n1;i++)cout<<l[i].cnt<<" "<<l[i].s<<'\n';
	for (ll i=mid;i<=n;i++){
		r[i-mid+1].s=s1[i],r[i-mid+1].cnt=s[i];
	}
	ll n2=n-mid+1;
//	cout<<"\n\n\n";
//	for (ll i=1;i<=n2;i++)cout<<r[i].cnt<<" "<<r[i].s<<'\n';
//	cout<<"\n\n\n";
	ll ans=0;
	ll j=1;
	ll i=1;
	//cout<<n2<<endl;
	while(i<=n1&&j<=n2){
		if (l[i].s!=r[j].s){
			//cout<<i<<" "<<j<<endl;
			//cout<<l[i].cnt<<" "<<r[j].cnt<<endl<<endl;
			//cout<<"min(l[i].cnt,r[j].cnt)£º"<<min(l[i].cnt,r[j].cnt)<<endl; 
			ans+=min(l[i].cnt,r[j].cnt);
			if (r[j].cnt<=l[i].cnt){
				j++;
			}
			if (r[j].cnt>=l[i].cnt)i++;
		}else{
			if (r[j].cnt<=l[i].cnt){
				j++;
			}
			if (r[j].cnt>=l[i].cnt)i++;
		}
	}
	//cout<<ans<<endl;
	if (i<n1){
		//cout<<i+1<<" "<<n1<<'\n';
		for (ll k=i+1;k<=n1;k++)ans+=l[k].cnt;
		cout<<ans;
		return 0;
	}
	if (j<n2){
		for (ll k=j+1;k<=n2;k++)ans+=r[k].cnt;
		cout<<ans;
		return 0;
	}
	cout<<ans;
	return 0;
} 
