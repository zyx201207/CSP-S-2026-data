#include<iostream> 
#include<string>
#include<cmath>
using namespace std;
int n;
char c[200005],cc[200005];
long long number[200005],cnumber[200005];
long long tot=0,mid,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n;
	long long t;
	for(int i=0;i<n;i++){
		cin>>cnumber[i];
		cin>>cc[i];
		tot+=cnumber[i];
	}
	
	long long l=-1,r=tot;
	long long bu=0;
	mid=tot/2;
	if(tot%2==0){
		mid--;
	}
	bool ok=0;
	for(int i=0;i<n;i++){
		l+=cnumber[i];
		if(l==mid){
			ok=1;
		}
		if(l>mid&&ok==0&&cnumber[i]>1){
			number[i+bu]=cnumber[i]-(l-mid)-1;
			c[i+bu]=cc[i];
			number[i+bu+1]=l-mid;
			c[i+bu+1]=cc[i];
			bu++;	
			ok=1;
		}
		else{
			number[i+bu]=cnumber[i];
			c[i+bu]=cc[i];
		}
	}
	l=-1;
	n+=bu;
	if(tot%2){
		for(int i=0;i<n;i++){
			l+=number[i];
			r-=number[n-1-i];
			if(l<=mid&&r>=mid){
				if(c[i]!=c[n-1-i]){
					if(number[i]>number[n-1-i]){
						ans+=number[n-1-i];
						number[i]-=number[n-1-i];
						n--;
						i--;
					}else if(number[i]==number[n-1-i]){
						ans+=number[n-1-i];
					}else{
						ans+=number[i];
						number[n-1-i]-=number[i];
						n++;
					}
				}
			}else{
				break;
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(l<mid&&r>=mid){
				if(c[i]!=c[n-1-i]){
					if(number[i]>number[n-1-i]){
						ans+=number[n-1-i];
						number[i]-=number[n-1-i];
						n--;
						i--;
					}else if(number[i]==number[n-1-i]){
						ans+=number[n-1-i];
					}else{
						ans+=number[i];
						number[n-1-i]-=number[i];
						n++;
					}
				}
			}else{
				break;
			}
			l+=number[i];
			r-=number[n-1-i];
		}
	}
	cout<<ans;
	return 0;
}
