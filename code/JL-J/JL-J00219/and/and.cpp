#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2*10e5+5;
struct Num{
	int num;
	int data;
	}nums[MAXN];
bool cmp(Num a,Num b){
	return a.data > b.data;
	}
int ans=-1,deans=0x3f3f3f3f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int tem;
	for (int i=1;i<=n;i++){
		cin >> nums[i].num;
		tem = nums[i].num;

		while (tem!=0){
			nums[i].data += tem&1;
			tem/=2;
			}
		}
	sort(nums+1,nums+1+n,cmp);
	int x=1;
//	for (int i=1;i<=n;i++){
//		cout << nums[i].num << ' ' << nums[i].data << endl;
//		}
	for (int i=1;i<=m;i=x){
		ans=-1;
		while (nums[x].data==nums[i].data){
			ans = max(nums[x].num,ans);
//			cout << ans << "**";
			x++;
			}
		deans = min(ans,deans);
		}
	cout << deans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}

