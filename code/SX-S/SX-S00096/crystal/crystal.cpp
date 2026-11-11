#include<bits/stdc++.h>
using namespace std;
#define int long long
long long n,m,a[500005],ans=-INT_MAX,sum,l,r,mid,vis[5],bs;
/*注释打开头防止没写星杠
F1：想到二分答案：第一种，二分水晶颗数，不好做，第二种二分每颗能量不好做
能不能证明每颗经操作后的小水晶一定等于原先一颗的大小呢，应该可以，因为只加不减
例如样例1，反正大概就是因为不选原先大小没优势，那么我们有一个n方的做法，显然太大了
还是用二分搜大小吧，那么就可以先排序，lr遍历坐标，找到一个后，由这个坐标回头减，看有几个相等的
F2 刚刚发现一个问题，在算定o后我不知道lr往那边去取，及时止损不写了写二分单个长度去
我已绝望，大体正确，样例12随便过，样例34各输出少了11和35，到底是为啥
找到原因了，我是sb*/

long long check(long long x){

//check函数控制m，先遍历找到第一次比mid大的值，mid改取这个值的前一个（无论是否等于，若等于说明刚好取对了，不等于就取数组里有的那个数字（刚刚的推断）

	long long sum = 0;
	for(int j = n;j>=1;j--){
		if(mid-a[j] > x){//这一个加上超了
			return sum;
		}
		else if(a[j] <=mid){

			x=x-mid+a[j];
			sum++;
		}
	}
	return sum;
}
void efcz(long long l,long long r){
	if(l>r)return;
	mid = (l+r)/2;
	long long o = check(m);
bs++;
	if(o>ans){
		ans = o;
	}
	efcz(mid+1,r);
	efcz(l,mid-1);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin >>n >> m;
	long long cz = 0;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(i!=1){
			if(i==2){
				cz = a[2]-a[1];
			}else{
				if(a[i]-a[i-1]!=cz){
					cz = INT_MIN;
				}
			}
		}
	}
	if(cz!=INT_MIN){//两种等差特判
	ans = 1;
		if(cz == 1){
		while(m>0){
			ans++;
			m-=cz;
			cz++;
		}
		}
		else{
			int p = cz;
			while(m-p>0){
				ans++;
				m-=p;
				p+=cz;
			}
		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1);//排序，准备二分
	l = a[1],r = a[n],mid = (long long)(ceil((l+r)/2));//rlmid都取长度
//mid = 4;			cout << check(m) << endl;
	efcz(l,r);
/*	while(l<=r){
		mid = (int)(ceil((l+r)/2));
//mid =71;
		cout << "*" << mid<<endl;
		long long o = check(m);//check里头控制m即可
		if(o>ans){//数量
			ans = o;//可行不是说明找小了！可行只是说明了这个情况可行，我操我为啥要说废话了
			l =mid+1;
		}else{
			r = mid-1;
		}
		cout << "#"<< ans << endl;
	}
			//cout << "*" << mid<<endl;*/
		//	cout <<"*"<<bs<<"#";
	cout << ans;

	return 0;
}