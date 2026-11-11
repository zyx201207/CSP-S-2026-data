/*
把问题转化为路径问题：
所有的点，到哪个点的总距离最短？ 
得到n（n%2 == 0）的点的目标点，则目标点必须位于(n/2)(n/2+1)两个点之间
得到n(n%2 == 1)的点的目标点，则目标点为(n + 1)/2 的点 
计算全部点到达目标点的总距离，从小到大排序，然后看m最多可以完成几个
初步计算时间复杂度为O(n)，应当可行*/
/*
新思路：
初始t点设定为目标点，但是应当实时变化。
如果我们取一个不用变化t点的点所要的代价大于变化t点带来的代价，那就应该果断动t点
问题是，动了t点之后，dis数组的数据无法实时更新
无所谓，我们可以时刻记录当前dis数组中存在的误差
然后用两个数组进行记录，分别记录与原始t点距离正负的数 
其中，优先选负的数 
*/ 
#include <bits/stdc++.h>
using namespace std;

long long n,m;

long long a[500005];

long long t,ans;

long long disf[500005]; //与原始t点距离为负的点的距离集合
long long disz[500005]; //与原始t点距离为正的点的距离集合 
long long idf, idz; //对应两集合大小 

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n % 2 == 0) {
		t = n / 2;
	}
	else {
		t = (n+1) / 2;
	} //获得原始t点 
	sort(a+1,a+n+1); //排序以获得大小关系 
	for (int i = 1; i <= n; i++) {
		if (a[i] <= a[t]) { //与原始t点相等的点也应该放在负集中优先选择 
			disf[++idf] = abs(a[i] - a[t]);
		}
		else {
			disz[++idz] = abs(a[i] - a[t]);
		}
	}//正负集合构建完成 
	/*for (int i =1; i <= idf; i++) {
		cout << disf[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= idz; i++) {
		cout << disz[i] << " ";
	}
	cout << endl;*/
	sort(disf+1,disf+idf+1);
	sort(disz+1,disz+idz+1); //排序，来贪心 
	long long tp = t; //计算误差：我们目前的t点相对于标准t点，向右偏移了多少？ 
	for (int i=1,j=1; ;) { //定义i为目前负集的下表，j为正集的下标 
		//初始ans为0，需要特判
		int cost = -1;
		if (ans != 0 && j <= idz) { //计算如果当前向右偏移一个下标，造成的代价 
			cost = ans * abs(disz[j] - disz[j-1]);
		} 
		//比较当前取正集划算还是取负集划算
		//cout << disf[i] + disz[j - 1] << " " << cost << endl;
		//cout << m << " " << cost << endl;
		if ((disf[i] + disz[j - 1] > cost && cost != -1) && m >= cost && j <= idz) { //处理负集误差，原负集加上当前偏移度（ 正集现标准点距离-原标准点距离） 
			j++;
			ans++;
			m -= cost;
		} 
		else if (i > idf && (m >= cost && j <= idz)) {
			j ++;
			ans++;
			m -= cost;
		}
		else if ((disf[i] + disz[j-1] <= cost || cost == -1) && m >= disf[i] + disz[j-1] && i <= idf) { //走负集 
			m -= disf[i] + disz[j-1];
			i++;
			ans++;
		}
		else if ((m < cost && cost != -1) && m < disf[i] + disz[j-1]) {
			break;
		}
		else if (i > idf && j > idz) {
			break;
		}
		else if ((i <= idf && j > idz) && m < disf[i] + disz[j-1]) break;
		else if ((i > idf && j <= idz) && m < cost) break;
		//cout << m << " " << cost << " ";
		//这里存在一个问题，如果已经出现了误差，那么dis数组也已经有误差了，不能再这样计算了。
		//如果正集中出现路径变长的情况，那么变长的点一定已经被取了，所以不用额外处理，只需要处理变短的点即可
		//但是我们使用cost代替计算边的长度，换言之，我们直接计算了导致的误差，而非边的长度，所以正集可以忽略误差 
	}
	cout << ans << endl;
	return 0;
} 
