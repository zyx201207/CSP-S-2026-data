#include<bits/stdc++.h> 
using namespace std;
long long n;
long long a[200005];
char c[200005];
long long cnt = 0;//修改次数 
long long l[200005], r[200005], dout=0;
char lc[200005], rc[200005];
void hwdx(long long a, char n, long long b, char m){
	if(dout==0){//没有没消掉的 
		if(a==b){
			if(n==m) cnt+=0;
			else cnt+=b;
		}else{
			if(a>b){
				if(n==m){
					l[1]=a-b;
					lc[1]=n;
					dout-=a-b;
				}else{
					l[1]=a-b;
					lc[1]=n;
					dout-=a-b;
					cnt+=b;
				}
			}else{
				if(n==m){
					r[1]=b-a;
					rc[1]=m;
					dout+=b-a;
				}else{
					r[1]=b-a;
					rc[1]=m;
					dout+=b-a;
					cnt+=a;
				}
			}
		}
	}else if(dout<0){//上一次左边多出来没消掉的 
		if(l[1]==b){
			if(lc[1]==m){
				cnt+=0;
				l[1]-=b;
				dout+=b;
			}else{
				cnt+=b;
				l[1]-=b;
				dout+=b;
			}
		}else{
			if(l[1]>b){
				if(lc[1]==m){
					l[1]-=b;
					cnt+=0;
					dout+=b;
				}else{
					l[1]-=b;
					cnt+=b;
					dout+=b;
				}
			}else{
				if(lc[1]==m){
					cnt+=0;
					dout+=l[1];
					l[1]-=l[1];
				}else{
					cnt+=l[1];
					dout+=l[1];
					l[1]-=l[1];
				}
				}
		}
		//先消掉上一次的 
	}else{//上一次右边多出来没消掉的
		if(r[1]==a){
			if(rc[1]==n){
				cnt+=0;
				r[1]-=a;
				dout-=a;
			}else{
				cnt+=a;
				r[1]-=a;
				dout-=a;
			}
		}else{
			if(r[1]>a){
				if(rc[1]==n){
					r[1]-=a;
					cnt+=0;
					dout-=a;
				}else{
					r[1]-=a;
					cnt+=a;
					dout-=a;
				}
			}else{
				if(rc[1]==n){
					cnt+=0;
					dout-=r[1];
					r[1]-=r[1];
				}else{
					cnt+=r[1];
					dout-=r[1];
					r[1]-=r[1];
				}
			}
		}
	}//先消掉上一次的
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!记得取消注释 
	
	//输入
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	//计修改次数
	int j=1; 
	for(int i=1;i<=n/2;i++){
		hwdx(a[i], c[i], a[n-i+1], c[n-i+1]);
		j=i;
	}
	if(n%2!=0){
		j+=1;
		hwdx(a[j], c[j], a[n-j+1], c[n-j+1]);
	}//奇数可能还会漏一次 
	//输出cnt
	cout << cnt;
	
 		
	return 0;
} 
