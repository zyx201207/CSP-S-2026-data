#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a1[200005],a2[200005],cnt1,cnt2,ans;
char c1[200005],c2[200005];
vector<ll> jd;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	jd.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>c1[i];
		a2[n-i+1]=a1[i];
		c2[n-i+1]=c1[i];
		/*cnt1+=a1[i];
		cnt2+=a2[n-i+1];
		if(cnt1==cnt2) jd.push_back(cnt1);
		else jd.push_back(cnt1),jd.push_back(cnt2);*/
	}
	for(int i=1;i<=n;i++){
		cnt1+=a1[i];
		cnt2+=a2[i];
		if(cnt1==cnt2) jd.push_back(cnt1);
		else jd.push_back(min(cnt1,cnt2)),jd.push_back(max(cnt1,cnt2));
	}
	/*ll id1=0,j1=1,id2=0,j2=1,idx=1;
	while(idx<=(cnt+1)/2){
		if(id1>=a1[j1]) j1++,id1=0;
		if(id2>=a2[j2]) j2++,id2=0;
		idx++;id1++,id2++;
		if(c1[j1]!=c2[j2]) ans++;	
	}*/
	//for(int i=0;i<jd.size();i++) cout<<jd[i]<<'\n';
	//---------------------------------
	ll j1=0,j2=0,cn1=0,cn2=0,jdi=1;
	while(j1<=n && j2<=n && cn1<=cnt1 && cn2<=cnt2 && jdi<jd.size()){
		//cout<<j1<<' '<<j2<<' '<<cn1<<' '<<cn2<<' '<<jdi<<'\n';
		//------------
		while(jd[jdi]>cn1 && j1<=n) j1++,cn1+=a1[j1];
		while(jd[jdi]>cn2 && j2<=n) j2++,cn2+=a2[j2];
		if(cn1>=jd[jdi] && cn2>=jd[jdi] && jdi<jd.size()){
			if(c1[j1]!=c2[j2]) ans+=jd[jdi]-jd[jdi-1];
			//cout<<c1[j1-1]<<' '<<c2[j2-1]<<'\n';
			//--------------------------------
			//cout<<jd[jdi]<<'\n';
			jdi++;
		}
		//j1++,j2++;
		//cout<<j1<<' '<<j2<<' '<<cn1<<' '<<cn2<<' '<<jdi<<'\n';
		//------------
	}
	//cout<<'\n';
	//---------------------------------------------------------------
	cout<<ans/2;
	return 0;
}
