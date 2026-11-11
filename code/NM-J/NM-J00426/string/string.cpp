#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	
	vector<pair<long long,char>> a(n+1);
	long long len=0;
	for(int i=0;i<n;++i)
	{
		
		cin>>a[i].first>>a[i].second;
		len+=a[i].first;
	}
	long long outof=0,s=0;
	long long as=len;
	if(len%2==1)as+=1;
	for(int i=0;i<n;++i){
		
		if(outof+a[i].first>as/2){
			s=i;
			break;
		}
		outof+=a[i].first;
	}
	
	if(len%2==1)as+=2;
	len/=2;
	as/=2;
	
	long long a1=len-outof,a2=outof+a[s].first-as+1;
	int l=s,r=s;
	if(len<=outof) {l--;a1=a[l].first;}

	long long ans=0;
	while(l>=0&&r<n){
		if(a1<a2){
			if(a[l].second!=a[r].second){
				
				ans+=a1;

			}
			a2-=a1;
			if(l>0){
				
				a1=a[l-1].first;
			}l--;
				
		}else if(a1>a2){
			if(a[l].second!=a[r].second){
				
				ans+=a2;

			}
			a1-=a2;
			if(r<n-1){
				
				a2=a[r+1].first;
			}r++;
				
		}
		else{
			if(a[l].second!=a[r].second){
				
				ans+=a1;

			}
			a2-=a1;
			a1=0;
			if(l>0){
				
				
				a1=a[l-1].first;
			}l--;
			if(r<n-1){
				
				
				a2=a[r+1].first;
			}r++;
		}
	}
	
	//ans+=abs(a1-a2);
	
	cout<<ans;
	return 0;
}
