//wo jue de wo xian zai qu shu jiao shi yi ge fei chang hao de shi ji
//zhe yi ding hui zha bu bu bu wo shi fen nu de
//[1] + Done                       "/bin/gdb" --interpreter=mi --tty=${DbgTerm} 0<"/tmp/Microsoft-MIEngine-In-8lp6k9co.zl8" 1>"/tmp/Microsoft-MIEngine-Out-d6a6ixh6.jm0"
//noi@noi-virtual-machine:~/桌面/NM-J00448$ 
//this is the "sudo visudo" in noi ubuntu(I don`t know what I doing now)
/*# This file MUST be edited with the 'visudo' command as root.
#
# Please consider adding local content in /etc/sudoers.d/ instead of
# directly modifying this file.
#
# See the man page for details on how to write a sudoers file.
#
Defaults        env_reset
Defaults        mail_badpass
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
# Host alias specification
# User alias specification
# Cmnd alias specification
# User privilege specification
root    ALL=(ALL:ALL) ALL
# Members of the admin group may gain root privileges
%admin ALL=(ALL) ALL
# Allow members of group sudo to execute any command
%sudo   ALL=(ALL:ALL) ALL
# See sudoers(5) for more information on "#include" directives:
#includedir /etc/sudoers.d*/
//内容由铝生成(jia de)
/*2026 CCF 非专业级软件能力认证 CSP-J/S 2026 第二轮入门组 纸牌游戏(card)纸牌游戏(card)【题目描述】小 Z 正在玩一种单人纸牌游戏。
他有一叠特制的纸牌,共有 n 张,从上到下的点数依次为 a 1 , a 2 , . . . , a n 。每张牌的点数都是 1 到 m 之间的整数,且每种点数都出现
至少一次。小 Z 将进行 n 局相互独立的游戏。每局开始前,他会将所有牌按原顺序放回牌堆,并清空桌面。在第 i (1 ≤ i ≤ n) 局中,他跳过前 i 
− 1 张牌,依次打出第 i 张到第 n 张牌,这些牌的点数依次为 a i , a i+1 , . . . , a n 。桌面上的牌始终从左到右排成一行。打出一张点数
为 k 的牌时:• 若桌面上没有点数为 k 的牌,就将这张牌放在最右端;• 否则,收走桌面上点数为 k 的牌及其右侧的所有牌,再把这张牌放在最右端。被
收走的牌在本局中不再使用。由上述规则可知,任意时刻桌面上同一种点数的牌至多只有一张。最后一张牌打出后,本局游戏结束。例如,若桌面上从左到右
的牌的点数依次为 1, 4, 2,则打出一张点数为 3 的牌后,桌面上从左到右的牌的点数依次为 1, 4, 2, 3。接着打出一张点数为 4 的牌时,桌面上原
来点数为 4 的牌及其右侧的所有牌(点数依次为 4, 2, 3)被收走,再把新打出的 4 放在最右端,此时桌面上从左到右的牌的点数依次为 1, 4。你需要
帮助小 Z 依次求出,对于每个 i = 1, 2, . . . , m,在所有 n 局游戏中,有多少局结束时桌面上留有点数为 i 的牌。【输入格式】从文件 card.
in 中读入数据。输入的第一行包含两个正整数 n, m,分别表示牌的数量和点数种类数。输入的第二行包含 n 个正整数 a 1 , a 2 , . . . , a n
 ,依次表示小 Z 的牌从上到下的点数。【输出格式】输出到文件 card.out 中。输出一行 m 个非负整数,其中第 i (1 ≤ i ≤ m) 个整数表示在所
有 n 局游戏中,有多少局结束时桌面上留有点数为 i 的牌。【样例 1 输入】1 4 32 1 2 1 3第 11 页共 13 页2026 CCF 非专业级软件能力认证
CSP-J/S 2026 第二轮入门组 纸牌游戏(card)【样例 1 输出】13 1 4【样例 1 解释】对于第 1 局游戏,小 Z 依次打出点数为 1, 2, 1, 3 的
牌:1. 打出第 1 张牌(点数为 1)后,桌面上只有一张点数为 1 的牌;2. 打出第 2 张牌(点数为 2)后,桌面上从左到右的牌的点数依次为 1, 2;3. 
打出第 3 张牌(点数为 1)后,先收走桌面上点数为 1, 2 的两张牌,再放上新打出的 1,桌面上只有一张点数为 1 的牌;4. 打出第 4 张牌(点数为 3)
后,桌面上从左到右的牌的点数依次为 1, 3。因此第 1 局游戏结束时,桌面上从左到右的牌的点数依次为 1, 3。对于第 2 局游戏,小 Z 依次打出点数
为 2, 1, 3 的牌,结束时桌面上从左到右的牌的点数依次为 2, 1, 3。对于第 3 局游戏,小 Z 依次打出点数为 1, 3 的牌,结束时桌面上从左到右的
牌的点数依次为 1, 3。对于第 4 局游戏,小 Z 仅打出一张点数为 3 的牌,结束时桌面上只有一张点数为3 的牌。因此,在全部 4 局游戏中:• 有 3 
局游戏结束时,桌面上留有点数为 1 的牌,即第 1, 2, 3 局;• 有 1 局游戏结束时,桌面上留有点数为 2 的牌,即第 2 局;• 有 4 局游戏结束时,桌面
上留有点数为 3 的牌,即全部 4 局。【样例 2 输入】1 10 32 3 1 2 1 3 2 3 1 2 1【样例 2 输出】110 3 3【样例 3】见题目目录下的 card/
3.in 与 card/3.ans。该样例满足测试点 4 ∼ 6 的约束条件。第 12 页共 13 页2026 CCF 非专业级软件能力认证 CSP-J/S 2026 第二轮入门组 
纸牌游戏(card)【样例 4】见题目目录下的 card/4.in 与 card/4.ans。该样例满足测试点 7 ∼ 9 的约束条件。【样例 5】见题目目录下的 card/
5.in 与 card/5.ans。该样例满足测试点 15 ∼ 17 的约束条件。【样例 6】见题目目录下的 card/6.in 与 card/6.ans。该样例满足测试点 21,
22 的约束条件。【数据范围】对于所有测试数据,均有:• 2 ≤ n ≤ 5 × 10 5 ,1 ≤ m ≤ 3 × 10 5 ;• 对于所有 i (1 ≤ i ≤ n),均有 1 ≤ a 
i ≤ m;• 每种点数都出现至少一次,即对于所有 i (1 ≤ i ≤ m),均存在 j (1 ≤ j ≤ n) 满足 a j = i。测试点编号 n ≤ m ≤1 ∼ 3 5 24 ∼ 6
500 2005 000 3 0007 ∼ 910 ∼ 1213, 14215 ∼ 1718, 192 × 10 52010 521, 2223 ∼ 253 0005 × 10 53 × 10 5特殊性质无A无B无A无
特殊性质 A:a 1 ≤ a 2 ≤ · · · ≤ a n 。特殊性质 B:至多存在 4 999 个 i (1 ≤ i ≤ n − 1) 满足 a i ̸ = a i+1 。第 13 页共 13 页*/
#include<bits/stdc++.h>
using namespace std;
int rnl[1401],ptk[1401];
int n,pts,pty;
stack<int> r;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> pts;
    for(int i = 0;i < n;i++){
        cin >> ptk[i];
    }
    for(int j = 0;j < pts;j++){
        pty=0;
        for(int i = j;i < n;i++){
            r.push(ptk[i]);
            rnl[ptk[i]]++;
            if(rnl[ptk[i]]!=0){
                while(!r.empty()){
                    r.pop();
                }
                r.push(ptk[i]);
            }
        }
        while(!r.empty()){
            pty += r.top();
            r.pop();
        }
        cout << pty << ' ';
    }
}
//buxingle maidegaile zhegeshuangzhanduobancuole oh
//I can`t do it
//I will coming next year
//114514