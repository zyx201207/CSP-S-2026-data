#include <bits/stdc++.h>

using namespace std;

namespace Solve {
    string c1, s1, c2, s2;
    struct Ticket {
        int ps_train;
        int col_seat;
        int row_seat;
    };
    Ticket tickets[2] = {};
    int row_char_to_num(char a){
        if(a == 'F'){
            return 5;
        }
        return a - 'A' + 1;
    }
    void set_ticket(){
        char digitsa[] = {c1[0], c2[0]};
        char digitsb[] = {c1[1], c2[1]};
        for(int i = 0; i <= 1; i++){
            int digit_a = digitsa[i] - '0';
            int digit_b = digitsb[i] - '0';
            tickets[i].ps_train = digit_a * 10 + digit_b;
        }
        int seat_a1 = s1[0] - '0';
        int seat_b1 = s1[1] - '0';
        int seat_a2 = s2[0] - '0';
        int seat_b2 = s2[1] - '0';

        tickets[0].col_seat = seat_a1 * 10 + seat_b1;
        tickets[1].col_seat = seat_a2 * 10 + seat_b2;

        char seatrow1 = s1[2];
        char seatrow2 = s2[2];
        tickets[0].row_seat = row_char_to_num(seatrow1);
        tickets[1].row_seat = row_char_to_num(seatrow2);
    }

    void main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        freopen("travel.in", "r", stdin);
        freopen("travel.out", "w", stdout);

        
        cin >> c1 >> s1 >> c2 >> s2;
        set_ticket();
        if(tickets[0].ps_train != tickets[1].ps_train){
            cout << "0000";
            return;
        }else{
            cout << "1";
        }
        if(tickets[0].col_seat != tickets[1].col_seat){
            cout << "000";
            return;
        }else{
            cout << "1";
        }
        if((tickets[0].row_seat <= 3 && tickets[1].row_seat <= 3) || (tickets[0].row_seat >= 4 && tickets[1].row_seat >= 4)){
            cout << "1";
        }else{
            cout << "00";
            return;
        }
        if(tickets[0].row_seat - tickets[1].row_seat <= 1){
            cout << "1";
        }else{
            cout << "0";
        }
    }
}

int main() {
    Solve::main();
    return 0;
}