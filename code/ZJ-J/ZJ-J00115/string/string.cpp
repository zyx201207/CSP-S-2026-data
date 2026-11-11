#include<bits/stdc++.h> 
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	
	long long t,mini=0,maxa=0,ans=0;
	cin>>t;
	for(long long i=1;i<=t;i++){
		cin>>a[i]>>c[i];
		maxa=max(maxa,a[i]);
		ans+=a[i];
	}
	if(t*maxa<=100000000){
		string s;
		for(long long i=1;i<=t;i++){
			for(long long j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		for(long long i=0,j=s.size()-1;;i++,j--){
			if(i>=j) break;
			else if(s[i]!=s[j]) mini++;
		}
		cout<<mini<<'\n';
		return 0;
	}
	long long l=1,r=t;
		long long q1=0,q2=0;
		for(long long l=1,r=t;;){
			if(l>=r) break;
			if(q1!=0){
				while(1){
					if(l>=r){
						break;
					}
					if(q1<=a[r]){
						if(q1==a[r]) r--; 
						mini+=q1*(c[l]!=c[r]);
						q2=a[r]-q1; 
						q1=0;
						l++;
						break;
					}
					q1-=a[r];
					mini+=a[r]*(c[r]!=c[l]); 
					r--;
				}
			}
			if(q2!=0){
				while(1){
					if(l>=r) break; 
					if(q2<=a[l]){
						mini+=q2*(c[l]!=c[r]);
						if(q2==a[l]) l++;
						q1=a[l]-q2;
						q2=0;
						r--;
						break;
					}
					q2-=a[l];
					mini+=a[l]*(c[l]!=c[r]); 
					l++;
				}
			}
			if(l>=r){
				break;
			}
			if(a[r]>a[l]){
				mini+=a[l]*(c[r]!=c[l]);
				q2=a[r]-a[l]; 
				l++;
			}else if(a[r]<a[l]){
				mini+=a[r]*(c[r]!=c[l]);
				q1=a[l]-a[r]; 
				r--;
			}else if(a[r]==a[l]){
				mini+=a[l]*(c[r]!=c[l]);
				l++,r--;
			}
		}
	cout<<mini;
	return 0;
} 
