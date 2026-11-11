#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cha[200005],cnt,sum=1,s,l,lin;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>5000){
		for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		cnt+=cha[i]*sum;
		if(cnt>m){
			break;
		}
		else if(cnt==m){
			sum++;
			
		}
		else{
			sum++;
		}
		
	}
	 cout<<sum;
	}
		
	else{
		for(int i=1;i<=n;i++){
			lin=0;
			s=0;
			for(int j=i-1;j>=1;j--){
			
				s+=a[i]-a[j];
				if(s>m){
					break;
				}
				else if(s==m){
					lin+=1;
					break;
				}
				else{
					lin+=1;
				}
			}
			l=max(l,lin);
		}
		cout<<l+1; 
	}
	
	
	return 0;
}

