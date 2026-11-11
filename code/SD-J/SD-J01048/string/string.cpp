#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

struct ss{
	char f;
	ll shu;
}ss1[200005],ss2[200005];

ll n,a[200005],s1,sum1,sum2,cnt,cnt1,cnt2,s11,s22;
char b[200005];

void hui(ll x){
	ll b1=sum1/2-sum2;
	ss1[++cnt1].f=b[x];
	ss1[cnt1].shu=b1;
	s11+=b1;
	for(int i=n;i>x;i--){
		ss2[++cnt2].f=b[i];
		ss2[cnt2].shu=a[i];
		s22+=a[i];
	}
	ss2[++cnt2].f=b[x];
	ss2[cnt2].shu=a[x]-b1;
	s22+=(a[x]-b1);
	if(s1){
		ss2[cnt2].shu-=1;
		s22--;
	}
	ll l=1,r=1;
	while(l<=cnt1&&r<=cnt2){
		if(ss1[l].shu<ss2[r].shu){
			if(ss1[l].f!=ss2[r].f){
				cnt+=ss1[l].shu;
			}
			ss2[r].shu-=ss1[l].shu;
			l++;
		}
		if(ss1[l].shu>ss2[r].shu){
			if(ss1[l].f!=ss2[r].f){
				cnt+=ss2[r].shu;
			}
			ss1[l].shu-=ss2[r].shu;
			r++;
		}
		else{
			if(ss1[l].f!=ss2[r].f){
				cnt+=ss1[l].shu;
			}
			l++;
			r++;
		}
	}
	
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%ld",&n);
	for(int i=1;i<=n;i++){
		scanf("%ld %c",&a[i],&b[i]);
		s1=(s1+a[i]%2)%2;
		sum1+=a[i];
	}
	for(int i=1;i<=n;i++){
		sum2+=a[i];
		if(sum2*2>=sum1){
			sum2-=a[i];
			hui(i);
			break;
		}
		ss1[++cnt1].f=b[i];
		ss1[cnt1].shu=a[i];
		s11+=a[i];
	}
	cout<<cnt;
	//cout<<endl<<s11<<' '<<s22;
	return 0;
}
