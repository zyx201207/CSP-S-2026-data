#include<bits/stdc++.h>
using namespace std;
int cmd(int x,int y){
	if(x<y){
		swap(x,y);
	}
}
long long s[2005];
long long n,m;
long long max2=0;
long long er(long long a,long long e){
	long long ejz=0;
	long long i=1;
	while(a!=0){
		ejz*=10;	
		ejz+=a%2;
		a/=2;
		i++;
	    }
	    if(e){
	    	return ejz;
		}
		else{
			return i;
		}

}
string shi(long long o){
	string a;
	int c=o;
	int i;
	for(i=1;c!=0;i++){
		c/=10;
	}
	for(int j=i;o!=0;j--){
		a[j]=o%10;
		o/=10;
	}
	return a;
}
long long sdf(long long a){
	long long h=1;
	for(long long i=1;i<=a;i++){
		h*=2;
	}
	return h;
}
long long awy(long long a,long long b){
	string x=shi(er(a,1));
	string y=shi(er(b,1));
	string z;
	long long p=min(er(a,0),er(b,0));
	for(long long i=1;i<=p;i++){
	    if(x[i]==y[i]&&x[i]==1){
	 	z[i]=1;
	    }
	    else{
	 	z[i]=0;
	    }
    }
    long long ans=0;
    for(long long i=p,j=1;i>=1;i--,j++){
    	ans+=z[j]*sdf(i);
	}
	return ans;
}
long long jy(long long a,long long b,long long i){
		a=awy(a,b);
		i++;
		b=s[i];
		jy(a,b,i);
		if(i==n){
			return a;
		}
}
	
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
    	cin>>s[i];
	}
	sort(s+1,s+n+1,cmd);
	if(m==1){
		cout<<s[1];
	}
	else{
		if(m==n){
			cout<<s[n];
		}
		else{
			cout<<s[2];
		}
	}
	fclose(stdin);
	fclose(stdout);
return 0;
} 
