#include<bits/stdc++.h>
using namespace std;
int n;
long long l=0,ans=0;
struct t{
	long long len;
	string c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
	}
	for(int I=1,J=n;I<J;){
		int Il=a[I].len,Jl=a[J].len;
		if(Il==Jl){
			if(a[I].c!=a[J].c){
				ans+=Il;
			}
			I++;
			J--;
		}else if(Il<Jl){
			if(a[I].c!=a[J].c){
				ans+=Il;
			}
			I++;
			a[J].len-=Il;
		}else{
			if(a[I].c!=a[J].c){
				ans+=Jl;
			}
			J--;
			a[I].len-=Jl;
		}
	}
	cout<<ans;
	return 0;
} 
