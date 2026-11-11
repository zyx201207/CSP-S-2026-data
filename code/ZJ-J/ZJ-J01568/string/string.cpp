#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
long long a[200001],len[200001]={0},l1=0,l2=0,ans=0;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a1;
		char c1;
		cin>>a1>>c1;
		if(c1==c[cnt])a[cnt]+=a1;
		else cnt++,c[cnt]=c1,a[cnt]=a1;
	}
	n=cnt;
	for(int i=1;i<=n;i++)len[i]=len[i-1]+a[i];
	for(int i=1,j=n;i<=j;){
		if(i==j)break;
		if(l1==0&&l2==0){
			if(c[i]==c[j]){
				if(a[i]==a[j])i++,j--;
				else if(a[i]>a[j])l1=a[i]-a[j],j--;
				else l2=a[j]-a[i],i++;
			}
			else{
				if(a[i]==a[j])ans+=a[i],i++,j--;
				else if(a[i]>a[j])ans+=a[j],l1=a[i]-a[j],j--;
				else ans+=a[i],l2=a[j]-a[i],i++;
			}
		}
		else{
			if(l1!=0){
				if(c[i]==c[j]){
					if(l1==a[j])l1=0,i++,j--;
					else if(l1>a[j])l1=l1-a[j],j--;
					else l2=a[j]-l1,l1=0,i++;
				}
				else{
					if(l1==a[j])ans+=l1,l1=0,i++,j--;
					else if(l1>a[j])ans+=a[j],l1=l1-a[j],j--;
					else ans+=l1,l2=a[j]-l1,l1=0,i++;
				}
			}
			else if(l2!=0){
				if(c[i]==c[j]){
					if(a[i]==l2)l2=0,i++,j--;
					else if(a[i]>l2)l1=a[i]-l2,l2=0,j--;
					else l2=l2-a[i],i++;
				}
				else{
					if(a[i]==l2)ans+=l2,l2=0,i++,j--;
					else if(a[i]>l2)ans+=l2,l1=a[i]-l2,l2=0,j--;
					else ans+=a[i],l2=l2-a[i],i++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
