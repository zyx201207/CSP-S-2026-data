#include<bits/stdc++.h> 
using namespace std;

long long n,ans=0,sum=0,a[20005];
struct ls{
	string ci;
	int ai;
};
ls l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s[20005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		ans+=a[i];
	}
	l.ai=a[1],l.ci=s[1];
	r.ai=a[n],r.ci=s[n];
	int lc=0,rc=0;
	for(int i=1;i<=ans/2;i++){
		if(l.ai>0 && r.ai>0){
			if(l.ci!=r.ci)sum++;
			l.ai--;
			r.ai--;
		}
		else {
			if(l.ai==0){
				lc++;
				l.ci=s[lc];
				l.ai=a[lc];
			}
			if(r.ai==0){
				rc++;
				r.ci=s[n-rc];
				r.ai=a[n-rc];
			}
		}
		if(l.ai>0 && r.ai>0){
			if(l.ci!=r.ci)sum++;
			l.ai--;
			r.ai--;
		}
		
	}
	cout<<sum;
	return 0;
}
