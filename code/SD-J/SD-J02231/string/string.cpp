#include<bits/stdc++.h>
using namespace std;
long long n,sum,ans=0,num1=1,num2=1,p,i1,oo;
long long a[200005],a1[200005],a2[200005];
char c[200005],c1[200005],c2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	p=sum;
	sum=sum/2;
	oo=sum;
	bool tt=1;
	while(p!=0){
		if(a[i1]<=oo&&tt==1){
			a1[num1]=a[i1];
			c1[num1]=c[i1];
			p-=a[i1];
			oo-=a[i1];
			i1++;
			num1++;
		}
		else if(a[i1]>oo&&tt==1){
			a1[num1]=oo;
			c1[num1]=c[i1];
			a2[num2]=a[i1]-oo;
			c2[num2]=c[i1];
			p-=a[i1];
			oo=0;
			tt=0;
			i1++;
			num2++;
		}
		else{
			a2[num2]=a[i1];
			c2[num2]=c[i1];
			p-=a[i1];
			i1++;
			num2++;
		}
	}
	long long i=1,j=num2;
	while(sum!=0){
		if(a1[i]>=a2[j]){
			if(c1[i]!=c2[j]){
				ans+=a2[j];	
				a1[i]-=a2[j];
				sum-=a2[j];
				j--;
			}
			else{
				a1[i]-=a2[j];
				sum-=a2[j];
				j--;
			}
		}
		else if(a1[i]<=a2[j]){
			if(c1[i]!=c2[j]){
				ans+=a1[i];
				a2[j]-=a1[i];
				sum-=a1[i];
				i++;
			}
			else{
				a2[j]-=a1[i];
				sum-=a1[i];
				i++;
			}
		}
	}
	cout<<ans; 
	return 0;
}
