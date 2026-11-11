//SN-J00804 张馨月 西安翱翔中学 
#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long sum=0;
struct dat{
	int a;
	char c;
}ac[200005];
long long sl=0;
bool sf=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ac[i].a>>ac[i].c;
		sl+=ac[i].a;
		if(i!=1&&ac[i].c!=ac[i-1].c) sf=false;
	}
	if(sf){
		cout<<0;
		return 0;
	}
	//cout<<sl<<endl;
	
	long long mid;
	int l=0,r;
	mid=sl/2;
	//cout<<mid;
	if(sl%2==0){
		long long ans=0;
		while(ans<mid){
			l++;
			ans+=ac[l].a;
		}
		r=l;
		//cout<<l<<" "<<r;
		if(ans>mid){
			int ar=ans-mid,al=ac[l].a-ans+mid;
			if(ar>al){
				l--;
				//sum+=ar-al;
				ac[r].a=ar-al;
			}
			else if(al>ar){
				r++;
				//sum+=al-ar;
				ac[l].a=al-ar;
			}
			else{
				r++;
			}
		}
		if(ans==mid){
			r++;
		}
	}
	else{
		long long ans=0;
		while(ans<mid){
			l++;
			ans+=ac[l].a;
		}
		//cout<<l<<" "<<ans<<endl;
		r=l;
		if(ans==mid){
			r++;
			ac[r].a--;
		}
		//cout<<ans<<mid;
		if(ans>mid){
			int ar=ans-mid-1,al=ac[l].a-ans+mid;
			
			//cout<<ar<<" "<<al<<endl;
			
			if(ar>al){
				l--;
				//sum+=ar-al;
				ac[r].a-=al+1;
			}
			else if(al>ar){
				r++;
				//sum+=al-ar;
				ac[l].a=al-ar;
			}
			else{
				r++;
			}
		}
	}
	//cout<<l<<" "<<r<<endl;
	//cout<<ac[l].a<<" "<<ac[r].a<<endl;
	
	while(l>=1&&r<=n){
		if(ac[l].a>ac[r].a){
			if(ac[l].c==ac[r].c){
				//sum+=ac[l].a-ac[r].a;
				ac[l].a-=ac[r].a;
				r++;
			}
			else{
				sum+=ac[r].a;
				ac[l].a-=ac[r].a;
				r++;
			}
		}
		else if(ac[l].a<ac[r].a){
			if(ac[l].c==ac[r].c){
				//sum+=ac[r].a-ac[l].a;
				ac[r].a-=ac[l].a;
				l--;
			}
			else{
				sum+=ac[l].a;
				ac[r].a-=ac[l].a;
				l--;
			}
		}
		else{
			if(ac[l].c==ac[r].c){
				l--;
				r++;
			}
			else{
				sum+=ac[l].a;
				l--;
				r++;
			}
		}
		//cout<<l<<" "<<r<<endl;
	}
	cout<<sum;
		
	return 0;
}
