#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long sum,c,sjj;
int a[N];
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	sum/=2;
	if(sum%2) sum++;
	int i=1,j=n;
	long long num=0;
//	cout<<sum<<' ';
		while(num<sum){
			//if(num+a[i]>=sum) break;
			///cout<<i<<' ';
			if(s[i]!=s[j]){
				if(a[i]>a[j]){
					sjj+=a[j];
					num+=a[j];
					a[i]-=a[j];
					a[j]=0;
					
					j--;
				}
				else if(a[i]<a[j]){
					sjj+=a[i];
					num+=a[i];
					a[j]-=a[i];
					
					a[i]=0;
					i++;
					//break;
				}
				else{
					sjj+=a[j];
					num+=a[j];
					a[j]=a[i]=0;
					i++,j--;
					//break;
				}
			}
			else{
				if(a[i]>a[j]){
					num+=a[j];
					a[i]-=a[j];
					
					a[j]=0;
					j--;
				}
				else if(a[i]<a[j]){
					num+=a[i];
					a[j]-=a[i];
					
					a[i]=0;
					i++;
				//	break;
				}
				else{
					num+=a[j];
					a[j]=a[i]=0;
					
					i++,j--;
					//break;
				}
			}
		}
			
	//}
	cout<<sjj<<endl;
	return 0;
}