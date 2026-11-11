#include<bits/stdc++.h>
#define int long long
using namespace std;



const int cnt=9;
const int W=9,H=9; //搞错了，H才是宽度，W才是高度
const bool isShowIntroduction=1;



const int sW=W+1,sH=H+1;
bool mp[sW][sH],vis[sW][sH],flag[sW][sH],g[sW][sH];
int np[sW][sH];
const int dx[]={0,0,1,-1,1,1,-1,-1};
const int dy[]={1,-1,0,0,1,-1,1,-1};
int fc,lc;
string tips="";

void dfs(int x,int y,bool f){
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&x<=W&&y>=1&&y<=H&&np[xx][yy]!=-1&&!vis[xx][yy]){
			vis[xx][yy]=1;
			g[xx][yy]=1;
			if(np[xx][yy]==0||f==0)dfs(xx,yy,1);
		}
	}
}

void introduction(){
	if(isShowIntroduction)cout << "非常经典的扫雷\n操作方法是输入横行，纵列，以及操作类型。操作类型为1是挖开2是插旗，其实2是插旗其余任何输入都是挖开\n-：未发掘的地块\nn：数字是这里没有雷，显示周围八个格子的雷的总数\n.：发掘过的本身及周围八个格子没有雷的格子。\n@：插的旗子\n*：雷\ncnt：剩余雷数，需要注意的是，这个并不是你还没有标出的雷的数量，单纯是雷的总数减去你插旗的个数，仅供参考\n提示：若要关闭这些信息在全部变量isShowIntroduction中设置，默认为1。\n\n";
}

void clear(){
	system("cls");
}

void print(){
	clear();
	introduction();
	cout << "Tips："<< (tips=="\0"?"空":tips) << endl;
	cout << "\n\n ";
	for(int i=1;i<=H;i++)cout << " " << i;
	cout << "\n";
	for(int i=1;i<=W;i++){
		cout << i << " ";
		for(int j=1;j<=H;j++){
			if(!flag[i][j]){
				if(vis[i][j]){
					if(np[i][j]==-1)cout << "* ";
					else if(np[i][j]==0)cout << ". ";
					else cout << np[i][j] << " ";
				} else cout << "- ";
			} else cout << "@ ";
		}
		cout << endl;
	}
	cout << "\ncnt: " << cnt-fc << endl;
	cout << endl;
}

void print2(bool isWin){
	clear();
	introduction();
	if(isWin)cout << "Congratulations!";
	else cout << "Try again~";
	cout << "\n\n ";
	for(int i=1;i<=H;i++)cout << " " << i;
	cout << "\n";
	for(int i=1;i<=W;i++){
		cout << i << " ";
		for(int j=1;j<=H;j++){
			if(np[i][j]==-1)cout << "* ";
			else if(np[i][j]==0)cout << ". ";
			else cout << np[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int a;
	cin >> a;
	return ;
}


void generate_np(){
	for(int i=1;i<=W;i++){
		for(int j=1;j<=H;j++){
			int nnt=0;
			for(int k=0;k<8;k++){
				nnt+=mp[i+dx[k]][j+dy[k]];
			}
			np[i][j]=nnt;
			if(mp[i][j])np[i][j]=-1;
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	srand(time(0));
	int c=cnt;
	mp[W/2+1][H/2+1]=1;
	while(c){
		int x=rand()%9+1,y=rand()%9+1;
		if(!mp[x][y]){
			mp[x][y]=1;
			g[x][y]=1;
			c--;
		}
	}
	mp[W/2+1][H/2+1]=0;
	generate_np();
	dfs(W/2+1,H/2+1,0);
	vis[W/2+1][H/2+1]=1;
	g[W/2+1][H/2+1]=1;
	bool f=1;
	for(int i=1;i<=W;i++){
		for(int j=1;j<=H;j++){
			if(!g[i][j])f=0;
		}
	}
	if(f){
		print2(1);
		return 0;
	}
	print();
	while(1){
		int ox,oy,op;
		bool ti=0;
		cin >> ox >> oy >> op;
		if(op==2){
			if(vis[ox][oy]&&!flag[ox][oy]){
				int r=rand()%2;
				ti=1;
				if(r)tips="原则上来说旗子插在哪里都可以但是故意插在空地上……？";
				else tips="空地上插旗子是在给自己寻找心理安慰？";
			}
			if(flag[ox][oy]){
				fc--;
				flag[ox][oy]=0;
			} else {
				fc++;
				flag[ox][oy]=1;
			}
			if(!ti)tips="\0";
			print();
			continue;
		}
		if(mp[ox][oy]){
			print2(0);
			return 0;
		} else {
			g[ox][oy]=1;
			vis[ox][oy]=1;
			dfs(ox,oy,0);
			if(!ti)tips="\0";
			print();
		}
		bool f=1;
		for(int i=1;i<=W;i++){
			for(int j=1;j<=H;j++){
				if(!g[i][j])f=0;
			}
		}
		if(f){
			print2(1);
			return 0;
		}
	}
	return 0;
}