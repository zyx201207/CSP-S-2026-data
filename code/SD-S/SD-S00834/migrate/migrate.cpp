#include<bits/stdc++.h>
using namespace std;
int c,t,cc[301];
long long m,x[2000001],n,l,r;
char o;
long long read(){
	char ch=getchar();
	long long f=1,a=0;
	while(ch!='-'&&(ch<'0'||ch>'9'))
		ch=getchar();
	if(ch=='-'){
		f=-1;
		ch=getchar();}
	while(ch>='0'&&ch<='9'){
		a=a*10+(ch-'0');
		ch=getchar();}
	return a*f;}
int cou(int ll,int y,int z){
	if(z==0){
		if(x[cc[1]]-x[l]<=m&&x[r]-x[cc[cc[0]]]<=m){
			for(int i=2;i<=cc[0];i++){
				if(x[cc[i]]-x[cc[i-1]]>m)
					return 0;}
		}else
			return 0;
		return 1;}
	int s=0;
	for(int i=ll+1;i<=y-z;i++){
		cc[++cc[0]]=i;
		s+=cou(i,y,z-1);
		cc[0]--;}
	return s;}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
			x[i]=read();
		if(n<=3){
			printf("0\n");
			continue;}
		if(c>10){
			long long d=x[n]-x[n-1];
			if(d*2>m){
				printf("0\n");
			}else{
				printf("%lld\n",max((long long)0,n-m/d*2+1));}
		}else{
			int sum=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[j-1]>m)
						break;
					if(j<i+3)
						continue;
					if(x[j]-x[i]>m){
						int s=0;
						for(int k=i+1;k<j;k++){
							if(x[k]-x[i]<=m&&x[j]-x[k]<=m)
								s++;}
						if(s){
							if(s==2)
								sum++;
						}else{
							for(int k=2;;k++){
								l=i;r=j;cc[0]=0;
								if(cou(i,j,k)){
									if(cou(i,j,k)==2)
										sum++;
									break;}
							}
						}
					}
				}
			}
			printf("%d\n",sum);}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
