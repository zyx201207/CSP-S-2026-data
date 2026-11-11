#include<bits/stdc++.h>
using namespace std;
long long a1[200000],a2[200000];
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,z;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a1[i]>>c;
		s1+=c;
		z+=a1[i];
	}z/=2;
	long long k=0,b=z;
	for(int i=s1.size()-1;i>0;i--){
		if(z>a1[i]){
			a2[k]=a1[i];
			s2+=s1[i]; 
			z-=a1[i];
		}else{
			a2[k]=z;
			s2+=s1[i];
			break;
		}
		k++;
	}
	long long x=0,y=0,ans=0;
	while(x<=b&&y<=b){
		if(a1[x]==a2[y]){
			if(s1[x]!=s2[y]){
				ans+=a1[x];
			}
			x++;
			y++;
		}else{
			if(a1[x]>a2[y]){
				if(s1[x]!=s2[y]){
					ans+=a2[y];
				}
				a1[x]-=a2[y];
				y++;
			}else if(a1[x]<a2[y]){
				if(s1[x]!=s2[y]){
					ans+=a1[x];
				}
				a2[y]-=a1[x];
				x++;
			}
		}
		if(a1[x]==0||a2[y]==0){
			break;
		}
	}cout<<ans;
	return 0;
}
