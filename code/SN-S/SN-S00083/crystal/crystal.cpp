#include<bits/stdc++.h>
using namespace std;
long long a[1000000],cha[1000000],num=0,cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m; 
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n-1;i++){
		cha[i]=a[i+1]-a[i];
		cnt+=cha[i];
	}
	sort(cha,cha+n-1);
	while(m>0){
		if(m<cha[num]){
			break;
		}else{
			if(cnt!=0&&cnt!=n-1){
				m-=cha[num];
				num++;
			}else if(cnt==0){
				if(m==1){
					num++;
					m--;
				}else{
					num+=2;
					m-=2;
				}	
			}else{
				num=1;
				break;
			} 
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
