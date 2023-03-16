static rows = vec![vec![1, 2, 3], vec![4, 5, 6]];
static array = Array2D::from_rows(&rows)?;

fn main() {
    println!("{}", rows[1]);

}