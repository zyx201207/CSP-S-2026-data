# include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],b[1000000],m,k,sum,ma=INT_MIN,j,q;
bool f1=true,f2=true,f3=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			if(a[i]<a[i-1]){
				f1=false;
			}
			if(a[i]-a[i-1]!=1){
				f2=false;
			}
		}
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				f3=false;
			}
		}
	}
	if(f2==false&&f3==false){
		if(f1==false){
			sort(a+1,a+1+n);
		}
		for(long long i=1;i<=n;i++){
			j=i;
			k=m;
			sum=0;
			q=1;
			while(j-q>0){
				k-=(a[j]-a[j-q]);
				if(k<0){
					break;
				}
				else{
					sum++;
					q++;
				}
			}
			ma=max(ma,sum);
		}
		cout<<ma+1;
	}
	if(f2==true){
		q=1;
		while(1){
			m-=q;
			if(q>=n){
				break;
			}
			if(m<0){
				break;
			}
			else{
				q++;
				sum++;	
			}	 
		}
		sum++;
		cout<<sum;
	}
	if(f3==true&&f2==false){
		k=abs(a[2]-a[1]);
		q=1;
		while(1){
			j=q*k;
			m-=j;
			if(q>=n){
				break;
			}
			if(m<0){
				break;
			}
			else{
				q++;
				sum++;	
			}	 
		}
		sum++;
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
