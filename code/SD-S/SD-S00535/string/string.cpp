#include<bits/stdc++.h>
using namespace std;
long long n,t[200005],l,cnt1,f1,u1,cnt2,f2,u2,a[200005],b[200005],sum;
char c[200005],a1[200005],b1[200005],m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>c[i];
		l+=t[i];
	}
	while(1){
		f1++;
		cnt1+=t[f1];
		if(cnt1>=l/2){
			a[++u1]=t[f1]-cnt1+l/2;
			a1[u1]=c[f1];
			break;
		}
		else{
			a[++u1]=t[f1];
			a1[u1]=c[f1];
		}
	}
	f2=n+1;
	while(1){
		f2--;
		cnt2+=t[f2];
		if(cnt2>=l/2){
			b[++u2]=t[f2]-cnt2+l/2;
			b1[u2]=c[f2];
			break;
		}
		else{
			b[++u2]=t[f2];
			b1[u2]=c[f2];

		}
	}
	cout<<endl;
	for(int i=1,j=1;i<=u1,j<=u2;){
		if(a1[i]!=b1[j]){
			
			if(a[i]>b[j]){
				a[i]-=b[j];
				sum+=b[j];
				j++;
			}
			else if(a[i]==b[j]){
				sum+=b[j];
				i++;
				j++;
			}
			else{
				b[j]-=a[i];
				sum+=a[i];

				i++;
			}
		}
		else{
			
			if(a[i]>b[j]){
				a[i]-=b[j];
				j++;
			}
			else if(a[i]==b[j]){
				i++;
				j++;
			}
			else{
				b[j]-=a[i];
				i++;

			}
		}
	}
	cout<<sum;
	return 0;
}
