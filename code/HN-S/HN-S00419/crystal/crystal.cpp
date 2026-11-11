#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
__int128  m=0;
int tj=0;
int n;
__int128  a[N];
__int128 dq=0;
__int128 b[N];
__int128 zz=0;
__int128 a1[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	string m1="";
	cin>>m1;
	__int128  zp=1;
	for(int k=m1.size()-1;k>=0;k--){
		m+=zp*(m1[k]-'0');
		zp*=10;
	}
	for(int i=1;i<=n;i++){
		string m2="";
	cin>>m2;
	__int128 zp1=1;


	if(m2[0]=='-'){
	for(int k=m2.size()-1;k>=1;k--){
		a[i]+=zp1*(m2[k]-'0');
		zp1*=10;
	}
	a[i]=-a[i];
	}
	else{
			for(int k=m2.size()-1;k>=0;k--){
		a[i]+=zp1*(m2[k]-'0');
		zp1*=10;
	}	
	}
	}

//->ÅÅÐò 

	sort(a+1,a+n+1); 
a[0]=0;

  //Ö÷³ÌÐò->
  __int128 mi=a[1];
  int wz=1;
   for(int i=1;i<=n;i++){
   		dq+=(i-wz)*(a[i]-a[i-1]);
		   if(dq>m){
		   
	    while(i<n&&dq>m){
	    		wz++;
	    		mi=a[wz];
	    		dq-=((a[i]-mi)-(a[i+1]-a[i])*(i-wz));
	    		dq-=mi;
	    		i++;   
		}if(i==n){
			if(dq<=m){
				tj++;
			}
			cout<<tj;
	    	return 0;
	    }
}
		tj+=1;
   }
   cout<<tj;


}
