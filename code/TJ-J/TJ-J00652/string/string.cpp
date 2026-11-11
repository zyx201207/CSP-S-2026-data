#include<bits/stdc++.h>
using namespace std;
void read(long long &a){
	char ch;
	int f=1;
	for(;ch=getchar();){
		if('0'<=ch&&ch<='9'){
			a=ch-'0';
			break;
		}else if(ch=='-'){
			f*=-1;
		}
	}for(;ch=getchar();){
		if('0'>ch||ch>'9'){
			a*=f;
			return ;
		}a=a*10+(ch-'0');
	}
}long long n,a[1000000],s;
char b[1000000]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		b[i]=getchar();
	}for(int i=1,j=n;i<j;){
		if(b[i]!=b[j]){
			if(a[i]>a[j]){
				s+=a[j];
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				s+=a[i];
				a[j]-=a[i];
				i++;
			}else{
				s+=a[i];
				i++;
				j--; 
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				i++;
				j--; 
			}
		}
	}cout<<s;
} 
