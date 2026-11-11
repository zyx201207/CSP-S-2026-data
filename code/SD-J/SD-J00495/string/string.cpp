#include<bits/stdc++.h>
using namespace std;
long long a[(int)2e5+10][2],l,suma,n,le,ri,les,ris,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	//cout<<"n:"<<n<<"\n";
	l=1;
	a[0][1]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[l][0];
		//cout<<a[l][0]<<" "; 
		suma+=a[l][0];
		cin>>c;
		//cout<<c<<"\n";
		if(c-'a'==a[l-1][1]){
			a[l-1][0]+=a[l][0];
			a[l][0]=0;
		}
		else{
			a[l-1][1]=c-'a';
			l++;
		}
	}
	l--;
	le=0;
	ri=suma+1;
	les=0,ris=l+1;
	a[n+1][1]=-1;
	while(les<=ris&&les<=ris){
		les++;
		ris--;
		le+=a[les][0],ri-=a[ris][0];
		if(a[les][1]==a[ris][1]){
			if(a[les][0]<a[ris][0]){
				a[les+1][0]-=(a[ris][0]-a[les][0]);
				le+=(a[ris][0]-a[les][0]);
				ans+=(a[ris][0]-a[les][0]);
			}
			else if(a[les][0]>a[ris][0]){
				a[ris-1][0]-=(a[les][0]-a[ris][0]);
				ri-=(a[les][0]-a[ris][0]);
				ans+=(a[les][0]-a[ris][0]);
			}
		} 
		else{
			ans+=min(a[les][0],a[ris][0]);
			if(a[les][0]<a[ris][0]){
				int x=(a[ris][0]-a[les][0]);
				a[ris][0]=x;
				ri+=x;
				ris++;
			}
			else if(a[les][0]>a[ris][0]){
				int x=(a[les][0]-a[ris][0]);
				a[les][0]=x;
				le-=x;
				les--;
			}
		}
		//cout<<"les:"<<les<<" ris:"<<ris<<" le:"<<le<<" ri:"<<ri<<" ans:"<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
