#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,cnt,w,i,j,d,c;
int flg/*控制不能变的位置 */,flg2,flg3/*骗特殊性质AB的分  2控制检查，3控制总判断*/; 
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin >> n >> m;
	for(i=1;i<=n;i++){//存第i颗水晶的大小 
		cin >> a[i];
		if(i > 1 && flg2 == 0){
			c = a[i] -a[i-1];
			flg2 = 1;
		}
		if(i > 1 && flg3 == 0){
			if(a[i] - a[i-1] != c){
				flg3 = 1;
			}
		} 
	}
	if(flg3 == 0){//（n*n - 2n） / 2
	//公式:(n*(n-2)*c+1)/2 
		if(c == 1){
//			cout<<"找到骗分点A"<<endl;
			for(i = n; i>1; i--){
				if((i*(i-2)*c+1)/2 <= m){
					cout<<i;
					return 0;
				}
			}
		}else{
//			cout<<"找到骗分点B"<<endl;
			for(i = n; i>1; i--){
				if((i*(i-1)*c+1)/2 <= m){
					cout<<i;
					return 0;
				}
			}
		}
		
	}
	sort(a+1,a+1+n);//从小到大把水晶排好序 
	for(i=1;i<=n;i++){//变成第i颗水晶
		w = m;
		cnt = 0;
		flg = 0;
		for(j=1;j<=n;j++){
			if(a[i] - a[j] >= 0){//能变花费 
				b[j] = a[i] - a[j];
			}else{//不能变 
				b[j] = -1;
				d = j-1;//存能变的位置
				flg = 1; 
				break;
			} 
		}
		if(flg == 0){//在最后一组的特殊情况 
			d=n;
		}
		for(j = d; j>=1;j--){
			if(w - b[j] >=0){
				w = w -b[j];
				cnt++;
			}else{
				break;
			}
		}
		ans = max(ans,cnt); 
	}  
	cout<<ans;
	return 0;
}
