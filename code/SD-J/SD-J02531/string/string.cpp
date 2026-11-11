#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long cnt=0,s[N+5];
bool o,z;
char c[N+5];
int n,a[N+5];
vector<long long>a1;
vector<char>c1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		cnt+=a[i];
		s[i]=s[i-1]+a[i];
	}
	if(cnt%2==0){
		cnt/=2;
		o=0;
	}
	else{
		cnt=(cnt-1)/2;
		o=1;
	} 
	int qu;
	if(o==1){
		for(int i=1;i<=n;i++){
			if(s[i]>cnt){
				a[i]--;
				qu=i;
				break;
			}
		}
		for(int i=qu;i<=n;i++)s[i]--;
	}
	long long gay=0,dw=0;
	bool pppp=0;
	for(int i=1;i<=n;i++){
		if(pppp==0)gay+=a[i];
		if(gay>cnt){
			dw=a1.size()-1;
			if(cnt-s[i-1]>0){
				a1.push_back(cnt-s[i-1]);
				c1.push_back(c[i]);
				dw++;
			}
			if(a[i]-(cnt-s[i-1])>0){
				a1.push_back(a[i]-(cnt-s[i-1]));
				c1.push_back(c[i]);
			}
			pppp=1;
			gay=-1;
		}
		else{
			if(a[i]!=0){
				a1.push_back(a[i]);
				c1.push_back(c[i]);
				
			}
		}
	}
	//for(int i=0;i<a1.size();i++)cout<<i<<":"<<a1[i]<<" "<<c1[i]<<"\n";
	int l=0,r=a1.size()-1;
	long long ans=0;
	while(l<=dw&&r>dw){
		if(a1[l]>a1[r]){
			if(c1[l]!=c1[r]){
				ans+=a1[r];
			}
			a1[l]-=a1[r];
			r--;
		}
		else{
			if(a1[l]<a1[r]) {
				if(c1[l]!=c1[r]){
					ans+=a1[l];
				}
				a1[r]-=a1[l];
				l++;
			}else{
				if(c1[l]!=c1[r])ans+=a1[l];
				l++;
				r--;
			}
		}
	}
	cout<<ans;
} 
