#include<iostream>
int a[200007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	std::cin >> n >> m;
	for(int i=0;i<n;i++)std::cin >> a[i];
	if(m==1){
		int tmp=-0x3f3f3f;
		for(int i=0;i<n;i++)tmp=std::max(tmp,a[i]);
		std::cout << tmp;
	}
	else if(m==n){
		int tmp=a[0];
		for(int i=1;i<n;i++)tmp&=a[i];
		std::cout << tmp;
	}
	else if(m==2){
		int tmp=-0x3f3f3f;
		for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)tmp=std::max(tmp,a[i]&a[j]);
		std::cout << tmp;
	}
	else{
		int mmax=-0x3f3f3f;
		for(int i=0;i<(1<<n);i++){
			int tmp=-0x3f3f3f;
			int cnt=0;
			for(int j=0;j<n;j++){
				if((i&(1<<(j)))==0)continue;
				cnt++;
				if(tmp==-0x3f3f3f)tmp=a[j];
				else tmp&=a[j];
			}
			if(cnt==m)mmax=std::max(tmp,mmax);

		}
		std::cout << mmax;
	}
	return 0;
}
