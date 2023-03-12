//https://codeforces.com/problemset/problem/1792/C --1500
#include <iostream>
int main ()
{
  int t, n, p[200000];
  std::cin >> t;
  while (t--)
  {
    std::cin >> n;
    for (int i = 0; i < n; ++i)
      std::cin >> p[i];
  }
}

/*
// https://codeforces.com/problemset/problem/1792/B --1200
#include <iostream>
#include <algorithm>
int main ()
{
  int t, a[4], alice, bob, ans;
  std::cin >> t;

  auto apply = [&] (const int alice_dif, const int bob_dif, int &val)
    {
      val -= std::abs (alice_dif);
      ans += std::abs (alice_dif);
      alice += alice_dif;
      bob += bob_dif;
    };
  while (t--)
    {
      for (int i = 0; i < 4; ++i)
        std::cin >> a[i];
      alice = 0, bob = 0, ans = 0;

      apply (a[0], a[0], a[0]);

      if (alice > 0)
        {
          int temp = std::min (a[1], a[2]);
          ans += temp * 2;
          a[1] -= temp;
          a[2] -= temp;
        }

      apply ( std::min (bob  , a[1]), -std::min (bob  , a[1]), a[1]);
      apply (-std::min (alice, a[2]),  std::min (alice, a[2]), a[2]);

      apply (-std::min (std::min (alice, bob), a[3]), -std::min (std::min (alice, bob), a[3]), a[3]);

      std::cout << ans + (a[0] + a[1] + a[2] + a[3] > 0 ? 1 : 0) << std::endl;
    }
}
*/

/*
// https://codeforces.com/problemset/problem/1792/A --800
#include <iostream>
int main ()
{
  int t, n, h[100], h1;
  std::cin >> t;
  while (t--)
  {
    std::cin >> n;
    h1 = 0;
    for (int i = 0; i < n; ++i)
    {
      std::cin >> h[i];
      if (h[i] == 1)
        h1++;
    }
    std::cout << n - h1 / 2 << std::endl;
  }
}
*/

/*
// time limit on test 5
//https://codeforces.com/problemset/problem/1796/D --2000
#include <iostream>
#include <vector>
#include <algorithm>
struct data_t
{
  int i;
  long long sum;
};
int main ()
{
  int t, n, k, x;
  std::vector<int> a;
  std::vector<data_t> l, r;
 
  constexpr int max_n = 200000;
  a.reserve (max_n);
  l.reserve (max_n + 1);
  r.reserve (max_n + 1);
 
  std::cin >> t;
  while (t--)
  {
    std::cin >> n >> k >> x;
    a.resize (n);
    l.resize (n + 1);
    r.resize (n + 1);
 
    for (int i = 0; i < n; ++i)
      std::cin >> a[i];
 
    l[0] = {0, 0};
    for (int i = 0; i < n; ++i)
      l[i + 1] = {i + 1, l[i].sum + a[i]};
 
    r[n] = {n, 0};
    for (int i = n - 1; i >= 0; --i)
      r[i] = {i, r[i + 1].sum + a[i]};
 
    const long long full_sum = l[n].sum;
    long long ans = 0;
 
    if (x < 0)
    {
      x = -x;
      k = n - k;
    }
    auto adding = [k, x] (const int from_i, const int to_i) -> long long
    {
      const int cnt = to_i - from_i;
      return 1LL * (cnt <= k ? cnt : 2 * k - cnt) * x;
    };
    for (int to_i = 0; to_i <= n; ++to_i)
    {
      const int from_i = 0;

      const long long tm = adding (from_i, to_i);
      ans = std::max (ans, full_sum - l[from_i].sum - r[to_i].sum + adding (from_i, to_i));
    }

    for (int from_i = 0; from_i <= n; ++from_i)
    {
      const int to_i = std::min_element (r.begin () + from_i, r.end (),
      [from_i, &adding] (const data_t &a, const data_t &b)
      {
        return a.sum - adding (from_i, a.i) < b.sum - adding (from_i, b.i); 
      }) - r.begin ();

      const long long tm = adding (from_i, to_i);
      ans = std::max (ans, full_sum - l[from_i].sum - r[to_i].sum + adding (from_i, to_i));
    }
    std::cout << ans << std::endl;
  }
}
*/

/*
WRONG TRY
//https://codeforces.com/problemset/problem/1796/D --2000
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
constexpr int max_n = 200000;
struct data_t
{
  int i;
  long long sum;
};
int main ()
{
  int t, n, k, x;
  std::vector<int> a;
  std::vector<long long> l, r;
  std::multiset<long long> l_set;

  a.reserve (max_n);
  r.reserve (max_n + 1);
  r.reserve (max_n + 1);

  std::cin >> t;
  while (t--)
  {
    std::cin >> n >> k >> x;

    a.resize (n);
    for (int i = 0; i < n; ++i)
      std::cin >> a[i];

    l.resize (n + 1);
    l[0] = 0;
    for (int i = 0; i < n; ++i)
      l[i + 1] = l[i] + a[i];

    r.resize (n + 1);
    r[n] = 0;
    for (int i = n - 1; i >= 0; --i)
      r[i] = r[i + 1] + a[i];

    if (x < 0)
    {
      x = -x;
      k = n - k;
    }

    const long long full_sum = r[0];
    long long ans = 0;

    l_set.insert (l[1] + k > 0 ? x : -x);
    for (int to_i = 1; to_i <= n; ++to_i)
    {

      std::lower_bound (l.begin (), l.end (), 11, [] (auto, auto) { return 1; });
    }

    for (int from_i = 0; from_i <= n; ++from_i)
    {
      const int to_i = std::min_element (r.begin () + from_i, r.end (),
      [from_i, &adding] (const data_t &a, const data_t &b)
      {
        std::cout << "#" << from_i << "#";
      return a.sum - adding (from_i, a.i) < b.sum - adding (from_i, b.i); 
      }) - r.begin ();

      const long long tm = adding (from_i, to_i);
      ans = std::max (ans, full_sum - l[from_i].sum - r[to_i].sum + adding (from_i, to_i));
    }


    if (x >= 0)
    {
      auto adding = [k, x] (const int from_i, const int to_i) -> long long
      {
        const int cnt = to_i - from_i;
        return (cnt <= k ? cnt : 2 * k - cnt) * x;
      };
      for (int from_i = 0; from_i <= n; ++from_i)
      {
        const int to_i = std::min_element (r.begin () + from_i, r.end (),
        [from_i, &adding] (const data_t &a, const data_t &b)
        {
          std::cout << "#" << from_i << "#";
        return a.sum - adding (from_i, a.i) < b.sum - adding (from_i, b.i); 
        }) - r.begin ();

        const long long tm = adding (from_i, to_i);
        ans = std::max (ans, full_sum - l[from_i].sum - r[to_i].sum + adding (from_i, to_i));
      }
    }
    else
    {
      auto adding = [k, x, n] (const int from_i, const int to_i) -> long long
      {
        const int cnt = to_i - from_i;
        return (n - cnt >= k ? -cnt : cnt + k * 2 + n * 2) * x;
      };
      for (int from_i = 0; from_i <= n; ++from_i)
      {
        const int to_i = std::min_element (r.begin () + from_i, r.end (),
        [from_i, &adding] (const data_t &a, const data_t &b)
        {
        return a.sum - adding (from_i, a.i) < b.sum - adding (from_i, b.i); 
        }) - r.begin ();

        const long long tm = adding (from_i, to_i);
        ans = std::max (ans, full_sum - l[from_i].sum - r[to_i].sum + adding (from_i, to_i));
      }
    }
    std::cout << ans << std::endl;
  }
}
*/

/*
//https://codeforces.com/problemset/problem/1796/C --1600
#include <iostream>
#include <vector>
int main ()
{
  constexpr int max_i = 1000000;
  std::vector<int> d2 (1, 1);
  while (d2.back () * 2 <= max_i)
    d2.push_back (d2.back () * 2);

  constexpr int inf = 998244353;
  int t, l, r;
  std::cin >> t;
  while (t--)
  {
    std::cin >> l >> r;
    int mx_size = 0;
    for (int i = l; i <= r; i *= 2)
      ++mx_size;
    const int mx_l = r / d2[mx_size - 1];
    int cnt = mx_l - l + 1;
    if (mx_size >= 2)
    {
      const int mx_l2 = r / d2[mx_size - 2] / 3;
      if (mx_l2 >= l)
        cnt = (cnt + 1L * (mx_l2 - l + 1) * (mx_size - 1)) % inf;
    }
    std::cout << mx_size << " " << cnt << std::endl;
  }
}
*/

/*
//https://codeforces.com/problemset/problem/1796/B --1000
#include <iostream>
#include <string>
#include <set>
int main ()
{
  int t;
  std::cin >> t;
  std::string a, b;
  while (t--)
  {
    std::cin >> a >> b;
    if (a.front () == b.front ())
    {
      std::cout << "YES\n" << a.front () << "*\n";
      continue;
    }
    else if (a.back () == b.back ())
    {
      std::cout << "YES\n*" << a.back () << "\n";
      continue;
    }
    std::set<std::string> s2;
    for (int i = 1; i < a.size (); ++i)
      s2.insert (a.substr (i - 1, 2));
    bool ok = false;
    for (int i = 1; i < b.size (); ++i)
      if (s2.count (b.substr (i - 1, 2)))
      {
        ok = true;
        std::cout << "YES\n" << "*" + b.substr (i - 1, 2) + "*\n";
        break;
      }
    if (!ok)
      std::cout << "NO\n";
  }
}
*/

/*
//https://codeforces.com/problemset/problem/1796/A --800
#include <iostream>
#include <string>
int main ()
{
  int t, k;
  std::cin >> t;
  std::string f, s = "FBFFBFFB";
  s += s + s;
  while (t--)
  {
    std::cin >> k >> f;
    std::cout << (s.find (f) != std::string::npos ? "YES" : "NO") << std::endl;
  }
}
*/

/*
//https://codeforces.com/problemset/problem/1795/D --1600
#include <iostream>
#include <algorithm>
#include <vector>
int main ()
{
  constexpr int inf = 998244353;

  constexpr int dis = 150001;
  std::vector<long long> inv (dis);
  std::vector<long long> fact (dis);
  std::vector<long long> fact_inv (dis);
	inv[1] = 1;
	for( int i = 2; i < dis; i++)
		inv[i] = inf - (inf / i) * inv[inf % i] % inf;
	
	fact[0] = 1; 
	fact_inv[0] = 1; 
	for( int i = 1; i < dis; i++)
  {
		fact[i] = fact[i-1] * i % inf;
		fact_inv[i] = fact_inv[i - 1] * inv[i] % inf;
	}
	auto comb = [&] (int n, int k)
  {
		if (n < 0 || k < 0) return 0LL;
		if (n < k) return 0LL;
		return fact[n]*fact_inv[n-k] % inf * fact_inv[k] % inf;
	};

  int n, w[3];
  std::cin >> n;
  const int m = n / 3;
  long long ans = comb (m, m / 2);
  for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < 3; ++j)
        std::cin >> w[j];
      std::sort (w, w + 3);
      if (w[0] == w[2])
        ans = (ans * 3) % inf;
      else if (w[0] == w[1])
        ans = (ans * 2) % inf;
    }
  std::cout << ans << std::endl;
}
*/

/*
//https://codeforces.com/problemset/problem/1795/C --1500
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
  std::ios::sync_with_stdio (false);
  std::cin.tie (nullptr);
  int t, n;
  std::vector<long long> a, b, bsum, cnt, add;
  std::cin >> t;
  while (t--)
  {
    std::cin >> n;
    a.resize (n); b.resize (n);
    for (int i = 0; i < n; ++i)
      std::cin >> a[i];
    for (int i = 0; i < n; ++i)
      std::cin >> b[i];

    bsum.assign (n + 1, 0);
    for (int i = 0; i < n; ++i)
      bsum[i + 1] = bsum[i] + b[i];
    
    cnt.assign (n + 1, 0);
    add.assign (n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
      const int j = std::upper_bound (bsum.begin (), bsum.end (), bsum[i] + a[i]) - bsum.begin () - 1;
      cnt[j]--;
      add[j] += bsum[i] + a[i] - bsum[j];
    }

    for (int i = 1; i < n; ++i)
      cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; ++i)
      cnt[i] = i + 1 + cnt[i];

    for (int i = 0; i < n; ++i)
      std::cout << cnt[i] * b[i] + add[i] << " \n"[i == n - 1];
  }
}
*/

/*
// https://codeforces.com/contest/1783/problem/C -- 1700
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
int main ()
{
  int t, n, m;
  std::vector<int> A, wins;
  std::vector<std::pair<int, int>> a;
  std::cin >> t;
  while (t--)
  {
    std::cin >> n >> m;
    a.resize (n);
    A.resize (n);
    wins.resize (n);
    for (int i = 0; i < n; ++i)
    {
      wins[i] = i + 1;
      a[i].second = i;
      std::cin >> a[i].first;
      A[i] = a[i].first;
    }
    std::sort (a.begin (), a.end ());

    std::set<int> was;
    for (int i = 0; i < n; ++i)
    {
      if (m - a[i].first >= 0)
      {
        m -= a[i].first;
        was.insert (a[i].second);
        wins[a[i].second]--;
      }
      else
        break;
    }
    const int my_wins = was.size ();
    int i_next = std::upper_bound (wins.begin (), wins.end (), my_wins) - wins.begin ();
    if (i_next == n)
    {
      std::cout << "1\n";
      continue;
    }  
    if (wins[i_next] == i_next + 1)
    {
      for (int i = 0; i < n; ++i)
      {
        if (wins[i] == i + 1 || wins[i] == my_wins || m + A[i] - A[i_next] < 0)
          continue;
        wins[i]++;
        wins[i_next]--;
        break;
      }
    }
    int ans = n - (std::upper_bound (wins.begin (), wins.end (), my_wins) - wins.begin ()) + 1;
    std::cout << ans << "\n";
  }
}
*/

/*
// https://codeforces.com/problemset/problem/1783/B -- 1100
#include <iostream>
#include <vector>
int main ()
{
  int t, n, l, r, is, js;
  std::cin >> t;
  while (t--)
  {
    std::cin >> n;
    std::vector<std::vector<int>> v (n, std::vector<int> (n));
    l = 1; r = n * n; is = 0, js = 0;
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        v[i][is ? n - 1 - j : j] = js ? r-- : l++;
        js ^= 1;
      }
      is ^= 1;
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        std::cout << v[i][j] << " \n"[j == n - 1];
  }
}
*/

/*
// https://codeforces.com/problemset/problem/1783/A -- 800
#include <iostream>
#include <functional>
#include <map>
int main ()
{
  int t, n, a;
  std::cin >> t;
  while (t--)
  {
    std::map<int, int, std::greater<int>> m;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
      std::cin >> a;
      m[a]++;
    }
    if (m.size () == 1)
      std::cout << "NO";
    else
    {
      std::cout << "YES\n";
      std::cout << m.rbegin ()->first << " ";
      m.rbegin ()->second--;
      for (const auto &el : m)
        for (int i = 0; i < el.second; ++i)
          std::cout << el.first << " ";
    }
    std::cout << "\n";
  }
}
*/

/*
#include <iostream>
#include <string>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <list>

void clear_screen() {
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}

enum class symbolType : int {
  Rock = 0,
  Paper,
  Scissors,
  Lizard,
  Spock,
  COUNT
};

std::string enum_to_text(const symbolType symbol) {
  assert (symbol != symbol_t::COUNT);
  switch (symbol) {
    case symbolType::Rock:     return "Rock";     break;
    case symbolType::Paper:    return "Paper";    break;
    case symbolType::Scissors: return "Scissors"; break;
    case symbolType::Lizard:   return "Lizard";   break;
    case symbolType::Spock:    return "Spock";    break;
    case symbolType::COUNT:    return "";         break;
  };
  return "";
}

class gameEngine {
private:
  std::vector<symbolType> symbols;
  std::vector<std::vector<bool>> winTable;
public:
  gameEngine() {

  }
};

struct rules_data_t {
  symbol_t    symbol;
  std::string action_name;
  rules_data_t (const symbol_t _symbol, const std::string &&_action_name)
    : symbol(_symbol), action_name(std::move (_action_name))
  {}
};

std::vector<rules_data_t> simple_rules = {
    {symbol_t::Paper   , "covers"},
    {symbol_t::Rock    , "crushes"},
    {symbol_t::Scissors, "cuts"}
};

std::vector<rules_data_t> tbd_rules = {
    {symbol_t::Scissors, "cuts"},
    {symbol_t::Paper   , "covers"},
    {symbol_t::Rock    , "crushes"},
    {symbol_t::Lizard  , "poisons"},
    {symbol_t::Spock   , "smashes"},
    {symbol_t::Scissors, "decapitates"},
    {symbol_t::Lizard  , "eats"},
    {symbol_t::Paper   , "disproves"},
    {symbol_t::Spock   , "vaporizes"},
    {symbol_t::Rock    , "crushes"}
};

namespace utils {
  bool check_atoi(std::string const &s) {
    char *p = nullptr;
    std::strtol (s.c_str (), &p, 10);
    return p == &s[s.size ()];
  }

  std::string getline_or_exit() {
    std::string s;
    if (!std::getline(std::cin, s)) {
      std::cerr << "Error stdin! Unexpected exit, sorry.";
      exit(0);
    }
    if (s == "exit") {
      exit(0);
    }
    return s;
  }
}

class Game_t
{
  const std::string game_name = "Paper - Rock - Scissors";
  unsigned int num_of_turns = 0; // ordered num of turns (0 if infinity game)
  unsigned int cur_turns = 0;    // current turn
  bool infinity_game = false;
  
  std::vector<std::vector<bool>> win_table;
  bool is_first_winer(const symbol_t first, const symbol_t second);
  void show_help() const;
  void show_info () const;
  void ask_num_of_turns();
public:
  void init();
};

bool is_first_winer(const symbol_t first, const symbol_t second) {
  return true;
}

void Game_t::show_help() const {
  clear_screen ();
  std::cout <<
    "\t'" << game_name << "'\n"
    "Instruction for menu:"
    " - input 'help' to see this instruction\n"
    " - input 'start' to quick start\n"
    " - input 'start <n>' to play n turns\n\n"
    "Instruction for turns:"
    " - input '[R]ock' to play Rock\n"
    " - input '[P]aper' to play Rock\n"
    " - input '[S]cissors' to play Rock\n\n"
    << std::flush;
}

void Game_t::show_info() const {
  clear_screen ();
  std::cout <<
    "'" << game_name << "' is a game for two players.\n"
    "Each turn each player simultaneously display a symbol:\n"

    "-     Rock (press R on keyboard)\n"
    "-    Paper (press P on keyboard)\n"
    "- Scissors (press S on keyboard)\n\n"
    "The winner of the turn is determined by the following schema:\n"
    "- paper beats (wraps) rock\n"
    "- rock beats (blunts) scissors\n"
    "- scissors beats (cuts) paper.\n\n";
}

void Game_t::ask_num_of_turns() {
  std::cout <<
    "Input how many turns you want to play (or press Enter for quick launch).\n"
    "Num of turns = ";
  std::string s = utils::getline_or_exit();
  if (s.empty()) {
    infinity_game = true;
  }
  else if (utils::check_atoi(s)) {
    num_of_turns = atoi(s.data());
  }
  else {
    infinity_game = true;
    std::cout << "Warning: incorrect input, the game will continue until you enter 'exit'.\n";
  }
}

void Game_t::init() {
  std::cout << "\t" << game_name << "\n";
  show_help ();

  ask_num_of_turns();
}

int main()
{
  Game_t game;
  game.init();
}
*/
/*
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <mutex>
bool isPolindrom (long long i)
{
  std::vector<int> v; v.reserve (18);
  while (i > 0)
    v.push_back (i % 10), i /= 10;
  const int n = v.size ();
  for (int j = 0; j < n; ++j)
    if (v[j] != v[n - 1 - j])
      return false;
  return true;
}
int main ()
{
  std::cout << "The number of concurrent threads is " << std::thread::hardware_concurrency () << "\n";

//const long long max_dig = 1000000000000000000;
  const long long max_dig = 1000000000000000000;
  std::vector<long long> ans;

  if (0)
    {
      for (long long i = 1; i * i < max_dig; ++i)
        {
          if (isPolindrom (i) && isPolindrom (i * i))
            ans.push_back (i * i);
        }
      for (int i = 0; i < ans.size (); ++i)
        std::cout << i + 1 << " " << ans[i] << "\n";
      return 0;
    }


  const int threads_num = std::thread::hardware_concurrency () / 4;
  std::vector<std::thread> threads;
  threads.reserve (threads_num);
  std::mutex ans_mutex;
  for (int thread_num = 0; thread_num < threads_num; ++thread_num)
    {
      threads.emplace_back (std::thread ([&ans, thread_num, threads_num, &ans_mutex, max_dig]() {
          for (long long i = 1 + thread_num; i * i < max_dig; i += threads_num)
            {
              if (isPolindrom (i) && isPolindrom (i * i))
                {
                  ans_mutex.lock ();
                  ans.push_back (i * i);
                  //std::cout << i * i << ", ";
                  ans_mutex.unlock ();
                }
            } 
        }));
    }
  for (int thread_num = 0; thread_num < threads_num; ++thread_num)
    threads[thread_num].join ();

  std::sort (ans.begin (), ans.end ());
  for (int i = 0; i < ans.size (); ++i)
    std::cout << i + 1 << " " << ans[i] << "\n";
}
*/
/*
#include <iostream>
int main ()
{
  int t, n, k;
  std::cin >> t;
  while (t--)
    {
      std::cin >> n >> k;
      if (k == n - 1)
        {
          if (n <= 4)
            {
              std::cout << "-1\n";
            }
          else
            {
              std::cout << "0 2\n1" << " " << n - 3 << "\n" << n - 1 << " " << n - 2 << "\n";
              for (int i = 3; i < n / 2; ++i)
                std::cout << i << " " << n - i - 1 << "\n";
            }
        }
      else if (k == 0)
        {
          for (int i = 0; i < n / 2; ++i)
            std::cout << i << " " << n - i - 1 << "\n";
        }
      else
        {
          for (int i = 1; i < n / 2; ++i)
            {
              if (i == k || i == n - k - 1)
                {
                  std::cerr << k << " " << n - 1 << "\n";
                  std::cerr << n - k - 1 << " " << 0 << "\n";
                }
              else
                std::cout << i << " " << n - i - 1 << "\n";
            }
        }
    }
}
*/
/*
// https://codeforces.com/contest/764/problem/C -- 1600
#include <iostream>
#include <vector>
#include <set>

int n;
std::vector<std::vector<int>> v;
std::vector<int> c;
bool check (const int a, const int prev)
{
  for (int i : v[a])
    {
      if (i == prev)
        continue;
      if (c[a] != c[i] || !check (i, a))
        return false;
    }
  return true;
}
bool check2 (const int a)
{
  for (int i : v[a])
    {
      if (!check (i, a))
        return false;
    }
  return true;
}
int main ()
{
  std::cin >> n;
  v.resize (n);
  for (int i = 1; i < n; ++i)
    {
      int a, b;
      std::cin >> a >> b;
      a--; b--;
      v[a].push_back (b);
      v[b].push_back (a);
    }
  c.resize (n);
  for (int i = 0; i < n; ++i)
    std::cin >> c[i];
  for (int i = 0; i < n; ++i)
    {
      for (int j : v[i])
        if (c[i] != c[j])
          {
            if (check2 (i))
              std::cout << "YES\n" << i + 1 << "\n";
            else if (check2 (j))
              std::cout << "YES\n" << j + 1 << "\n";
            else
              std::cout << "NO\n";
            return 0;
          }
    }
  std::cout << "YES\n1\n";
}
*/
/*
//https://codeforces.com/problemset/problem/1629/B --800
#include <iostream>
#include <vector>
int main ()
{
  int t, l, r, k;
  std::cin >> t;
  while (t--)
    {
      std::cin >> l >> r >> k;
      if (l == r)
        std::cout << (l == 1 ? "NO\n" : "YES\n");
      else
        std::cout << ((r - l + 1) / 2 + (r % 2 == 1 && l % 2 == 1? 1 : 0) <= k ? "YES\n" : "NO\n");
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1629/A --800
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
  int t, n, k;
  struct T { int a, b; };
  std::vector<T> v;
  std::cin >> t;
  while (t--)
    {
      std::cin >> n >> k;
      v.resize (n);
      for (int i = 0; i < n; ++i)
        std::cin >> v[i].a;
      for (int i = 0; i < n; ++i)
        std::cin >> v[i].b;
      std::sort (v.begin (), v.end (), [](const T &a, const T &b) { return a.a < b.a; });
      for (int i = 0; i < n && k >= v[i].a; ++i)
        k += v[i].b;
      std::cout << k << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1628/B --1700
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
int main ()
{
  int t, n;
  std::vector<std::string> v;
  std::cin >> t;
  while (t--)
    {
      std::cin >> n;
      v.resize (n);
      bool ok = false;
      for (int i = 0; i < n; ++i)
        {
          std::cin >> v[i];
          if (ok) continue;
          ok = true;
          for (int j = 0; j <= v[i].size () / 2; ++j)
            if (v[i][j] != v[i][v[i].size () - 1 - j])
              {
                ok = false;
                break;
              }
        }
      if (!ok)
        {
          std::unordered_set<char> m1;
          std::unordered_map<char, std::unordered_set<char>> m2, m3d, m3_;
          std::unordered_map<char, std::unordered_set<std::string>> m3;
          for (int i = 0; i < n; ++i)
            {
              if (v[i].size () == 1)
                {
                  if (   (m1.count (v[i][0]))
                      || (m2.count (v[i][0]))
                      || (m3d.count (v[i][0])))
                    {
                      ok = true;
                      break;
                    }
                  m1.insert (v[i][0]);
                }
              else if (v[i].size () == 2)
                {
                  if (   (m1.count (v[i][1]))
                      || (m2.count (v[i][1]) && m2[v[i][1]].count (v[i][0]))
                      || (m3_.count (v[i][1]) && m3_[v[i][1]].count (v[i][0])))
                    {
                      ok = true;
                      break;
                    }
                  m2[v[i][0]].insert (v[i][1]);
                }
              else
                {
                  std::string ss = v[i].substr (1, 1) + v[i][0];
                  if (   (m1.count (v[i][2]) && v[i][0] == v[i][1])
                      || (m2.count (v[i][2]) && m2[v[i][2]].count (v[i][1]))
                      || (m3.count (v[i][2]) && m3[v[i][2]].count (ss)))
                    {
                      ok = true;
                        break;
                    }
                  m3[v[i][0]].insert (v[i].substr (1));
                  m3_[v[i][0]].insert (v[i][1]);
                  if (v[i][0] == v[i][1])
                    m3d[v[i][0]].insert (v[i][1]);
                }
            }
        }
      std::cout << (ok ? "YES" : "NO") << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1628/A --1400
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
int main ()
{
  int t, n, a;
  std::vector<std::queue<int>> v;
  std::vector<int> ans;
  std::cin >> t;
  while (t--)
    {
      std::cin >> n;
      ans.clear ();
      v.clear (); v.resize (n + 1);
      for (int i = 0; i < n; ++i)
        std::cin >> a, v[a].push (i);
      int mx = -1;
      while (mx < n - 1)
        {
          int i = 0;
          for (; i <= n; ++i)
            if (!v[i].empty ())
              {
                a = v[i].front (); v[i].pop ();
                mx = std::max (mx, a);
              }
            else
              {
                if (i == 0) ++mx;
                break;
              }
          for (int j = 0; j < i; ++j)
            while (!v[j].empty () && v[j].front () < mx)
              v[j].pop ();
          ans.push_back (i);
        }
      std::cout << ans.size () << "\n";
      for (int el : ans)
        std::cout << el << " ";
      std::cout << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1627/D --1900
#include <iostream>
#include <vector>
const int inf = 1000000;
int gcd (int a, int b)
{
  while (a && b) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
int main ()
{
  std::vector<int> a (inf + 1, 0);
  int n, b, ans = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i)
    std::cin >> b, a[b] = 1;
  for (int i = 1; i <= inf; ++i)
    if (!a[i])
      {
        int j = i * 2;
        while (j <= inf && !a[j])
          j += i;
        if (j > inf)
          continue;
        int tGCD = j;
        for (j += i; j <= inf; j += i)
          if (a[j])
            {
              tGCD = gcd (j, tGCD);
              if (tGCD == i)
                break;
            }
        if (tGCD == i)
          ++ans;
      }
  std::cout << ans << "\n";
}
*/
/*
//https://codeforces.com/problemset/problem/1627/C --1400
#include <iostream>
#include <vector>
#include <unordered_map>
int main ()
{
  int t, n, a, b;
  std::cin >> t;
  std::vector<std::vector<int>> v;
  std::unordered_map<long long, int> keys;
  std::vector<int> ans;
  while (t--)
    {
      std::cin >> n;
      keys.clear ();
      v.clear (); v.resize (n + 1);
      bool ok = true;
      for (int i = 1; i < n; ++i)
        {
          std::cin >> a >> b;
          if (v[a].size () > 1 || v[b].size () > 1)
            ok = false;
          if (!ok)
            continue;
          v[a].push_back (b);
          v[b].push_back (a);
          keys[1LL * a * 100001 + b] = i;
          keys[1LL * b * 100001 + a] = i;
        }
      if (!ok)
        {
          std::cout << "-1\n";
          continue;
        }
      int cur = 0;
      for (int i = 1; i < n; ++i)
        if (v[i].size () == 1)
          {
            cur = i;
            break;
          }
      ans.resize (n + 1);
      int next = v[cur][0];
      std::vector<int> val = {2, 3};
      int i = 0;
      while (true)
        {
          ans[keys[1LL * cur * 100001 + next]] = val[i];
          i = (i + 1) % 2;
          if (v[next].size () == 1)
            break;
          if (v[next][0] != cur)
            {
              cur = next;
              next = v[next][0];
            }
          else
            {
              cur = next;
              next = v[next][1];
            }
        }
      for (int i = 1; i < n; ++i)
        std::cout << ans[i] << " ";
      std::cout << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1627/B --1300
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
  int t, n, m;
  std::vector<int> v;
  std::cin >> t;
  while (t--)
    {
      std::cin >> n >> m;
      v.clear (); v.reserve (n * m);
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
          v.push_back (
            std::max (
              std::max (
                (i - 1) + (j - 1),
                (i - 1) + (m - j)),
              std::max (
                (n - i) + (j - 1),
                (n - i) + (m - j)))
            );
      std::sort (v.begin (), v.end ());
      for (int el : v)
        std::cout << el << " ";
      std::cout << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1627/A --800
#include <iostream>
#include <string>
#include <vector>
int main ()
{
  int t, n, m, r, c, ans;
  std::cin >> t;
  std::vector<std::string> v;
  while (t--)
    {
      std::cin >> n >> m >> r >> c;
      --r; --c;
      v.resize (n);
      for (int i = 0; i < n; ++i)
        std::cin >> v[i];
      if (v[r][c] == 'B')
        ans = 0;
      else
        {
          bool ok = false;
          for (int i = 0; i < n; ++i)
            if (v[i][c] == 'B')
              { ok = true; break; }
          for (int i = 0; i < m; ++i)
            if (v[r][i] == 'B')
              { ok = true; break; }
          if (ok)
            ans = 1;
          else
            {
              for (int i = 0; i < n && !ok; ++i)
                for (int j=0;j<m;++j)
                  if (v[i][j] == 'B')
                    { ok = true; break; }
              if (ok)
                ans = 2;
              else
                ans = -1;
            }
        }
      std::cout << ans << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1626/C --1700
#define IOS std::ios::sync_with_stdio (0), std::cin.tie (0);
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
  IOS
  int t, n;
  long long x;
  std::vector<int> k, h;
  std::cin >> t;
  while (t--)
    {
      x = 0;
      std::cin >> n;
      k.resize (n);
      for (int i = 0; i < n; ++i)
        std::cin >> k[i];
      h.resize (n);
      for (int i = 0; i < n; ++i)
        std::cin >> h[i];
      std::vector<std::pair<int, int>> v; v.reserve (n * 2);
      for (int i = 0; i < n; ++i)
        v.push_back ({k[i] - h[i],  1}),
        v.push_back ({k[i]       , -1});
      std::sort (v.begin (), v.end ());
      int sum = v[0].second, start = v[0].first;
      for (int i = 1; i < v.size (); ++i)
        {
          sum += v[i].second;
          if (sum == 0)
            {
              int end = v[i].first;
              x += 1LL * (end - start + 1) * (end - start) / 2;
              if (i < v.size () - 1)
                start = v[i + 1].first;
            }
        }
      std::cout << x << "\n";
    }
}
*/

/*
// https://codeforces.com/problemset/problem/1626/B --1100
#include <iostream>
#include <string>
#include <algorithm>
int main ()
{
  IOS
  int t, n;
  std::string s, ans, tmp;
  std::cin >> t;
  while (t--)
    {
      std::cin >> s; n = s.size ();
      ans = "";
      for (int i = n - 1; i > 0; --i)
        {
          const int val = (int)(s[i] - '0') + (int)(s[i - 1] - '0');
          if (val >= 10)
            {
              ans = (i > 1 ? s.substr (0, i - 1) : "")
                  + std::to_string (val)
                  + (i < n - 1 ? s.substr (i + 1) : "");
              break;
            }
        }
      if (ans.empty ())
        {
          int i = 1;
          const int val = (int)(s[i] - '0') + (int)(s[i - 1] - '0');
          ans = (i > 1 ? s.substr (0, i - 1) : "")
              + std::to_string (val)
              + (i < n - 1 ? s.substr (i + 1) : "");
        }
      std::cout << ans << "\n";
    }
}
*/
/*
// https://codeforces.com/problemset/problem/1626/A --800
#include <iostream>
#include <string>
#include <vector>
int main ()
{
  int t;
  std::cin >> t;
  std::vector<int> v (26);
  while (t--)
    {
      std::string s, ans;
      std::cin >> s;
      std::fill (v.begin (), v.end (), 0);
      for (const char c : s)
        v[c - 'a']++;
      for (int i = 0; i < v.size (); ++i)
        if (v[i] == 2)
          ans += (char)('a' + i);
      ans += ans;
      for (int i = 0; i < v.size (); ++i)
        if (v[i] == 1)
          ans += (char)('a' + i);
      std::cout << ans << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1625/C --1700
#include <iostream>
#include <vector>
#include <algorithm>
const int inf = 1000000000;
int main ()
{
  int n, l, k;
  std::cin >> n >> l >> k;
  std::vector<int> d (n + 1), a (n);
  for (int i = 0; i < n; ++i)
    std::cin >> d[i];
  d[n] = l;
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];

  std::vector<std::vector<int>> dp (n + 1, std::vector<int> (k + 1, inf));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= k; ++j)
      for (int pos = i + 1; pos <= n; ++pos)
        {
          const int h = j + pos - i - 1;
          if (h > k)
            continue;
          dp[pos][h] = std::min (dp[pos][h], dp[i][j] + a[i] * (d[pos] - d[i]));
        }
  int ans = inf;
  for (int i = 0; i <= k; ++i)
    ans = std::min (ans, dp[n][i]);
  std::cout << ans;
}
*/
/*//https://codeforces.com/problemset/problem/1625/B --1100
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
int main ()
{
  int t, n;
  std::vector<int> a;
  std::unordered_map<int, std::vector<int>> v (150000);
  std::cin >> t;
  while (t--)
    {
      std::cin >> n;
      a.resize (n);
      v.clear ();
      for (int i = 0; i < n; ++i)
        {
          std::cin >> a[i];
          v[a[i] - 1].push_back (i);
        }
      int ans = -1;
      for (const auto el : v)
        {
          const auto &w = v[el.first];
          for (int i = 1; i < w.size (); ++i)
            ans = std::max (n - w[i] + w[i - 1], ans);
        }
      std::cout << ans << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1625/A --800
#include <iostream>
#include <vector>
int main ()
{
  int t, n, l, a;
  std::cin >> t;
  std::vector<int> v;
  while (t--)
    {
      std::cin >> n >> l;
      v.clear (); v.resize (l);
      for (int i = 0; i < n; ++i)
        {
          int m = 0;
          std::cin >> a;
          while (a > 0)
            {
              if (a % 2 == 1)
                v[m]++;
              a /= 2;
              ++m;
            }
        }
      int ans = 0;
      for (int i = l - 1; i >= 0; --i)
        {
          if (n - v[i] < v[i])
            ans += 1;
          ans *= 2;
        }
      ans /= 2;
      std::cout << ans << "\n";
    }
}
*/
